#include "ft_printf.h"

int	ft_printer_int(char *str, long tmp, t_sf flags)
{
	int	n;

	n = 0;
	if (tmp < 0 && (flags.precision >= 0))
		n += ft_putchar('-');
	if (flags.precision >= 0)
		n += ft_print_w(flags.precision, ft_strlen(str), 1);
	n += ft_print_precision(ft_strlen(str), str);
	return (n);
}

int	ft_int(char *str, long tmp, t_sf flags)
{
	int	n;

	n = 0;
	if (flags.minus == 1)
		n += ft_printer_int(str, tmp, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		n += ft_print_w(flags.width, 0, 0);
	}
	else
		n += ft_print_w(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		n += ft_printer_int(str, tmp, flags);
	return (n);
}

int	ft_print_int(long t, t_sf flags)
{
	int		n;
	long	tmp;
	char	*str;

	n = 0;
	tmp = t;
	if (t == 0 && flags.precision == 0)
		return (ft_print_w(flags.width, 0, 0));
	if (t < 0 && (flags.precision >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.precision <= -1)
			n += ft_putchar('-');
		flags.width--;
		t = -t;
		if (flags.precision >= 0)
			flags.zero = 1;
	}
	str = ft_long_itoa(t);
	n += ft_int(str, tmp, flags);
	free(str);
	return (n);
}
