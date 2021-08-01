#include "ft_printf.h"

int	print_me(t_sf flags, va_list ap)
{
	if (flags.type == 'c')
		flags.lenght = ft_print_c(va_arg(ap, int), flags);
	if (flags.type == 's')
		flags.lenght = ft_print_str(va_arg(ap, char *), flags);
	if (flags.type == 'p')
		flags.lenght = ft_print_p(va_arg(ap, unsigned long long), flags);
	if (flags.type == 'd' || flags.type == 'i')
		flags.lenght = ft_print_int(va_arg(ap, int), flags);
	if (flags.type == 'u')
		flags.lenght = ft_print_uint((unsigned int)va_arg(ap, unsigned int),
				flags);
	if (flags.type == 'x')
		flags.lenght = ft_print_h(va_arg(ap, unsigned int), flags);
	if (flags.type == 'X')
		flags.lenght = ft_print_h(va_arg(ap, unsigned int), flags);
	if (flags.type == '%')
		flags.lenght = ft_print_c('%', flags);
	return (flags.lenght);
}

int	ft_check_type(const char *format, int i, t_sf *flags, va_list ap)
{
	while (format[i])
	{
		if (!ft_digit(format[i]) && !ft_flag(format[i])
			&& !ft_type(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '.')
			i = ft_precision(format, i, flags, ap);
		if (format[i] == '-')
			*flags = ft_minus(*flags);
		if (format[i] == '*')
			*flags = ft_star(*flags, ap);
		if (ft_digit(format[i]))
			*flags = ft_width(*flags, format[i]);
		if (ft_type(format[i]))
		{
			*flags = ft_hex(*flags, format[i]);
			break ;
		}
		if (i + 1 == (int)ft_strlen(format))
			return (i);
		i++;
	}
	return (i);
}

void	ft_parser_str(const char *format, t_sf *flags, va_list ap)
{
	int	i;

	i = 0;
	while (1)
	{
		ft_init_flags(flags);
		if (!format[i])
			break ;
		if (format[i] != '%')
			flags->lenght += ft_putchar(format[i]);
		if (format[i] == '%')
		{
			if (i + 1 == (int)ft_strlen(format))
				break ;
			if (format[i + 1] == ' ')
				flags->lenght += ft_putchar(format[++i]);
			i = ft_check_type(format, ++i, flags, ap);
			if (ft_type(format[i]))
				flags->lenght += print_me(*flags, ap);
			else
				flags->lenght += ft_putchar(format[i]);
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_sf		flags;

	flags.lenght = 0;
	va_start(ap, format);
	ft_parser_str(format, &flags, ap);
	va_end(ap);
	return (flags.lenght);
}
