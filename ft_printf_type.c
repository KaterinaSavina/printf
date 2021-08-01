#include "ft_printf.h"

int	ft_flag(int i)
{
	if (i == '-' || i == '0' || i == '.' || i == '*')
		return (1);
	else
		return (0);
}

int	ft_type(int i)
{
	if (i == 'c' || i == 's' || i == 'p' || i == 'd' || i == 'i'
		|| i == 'u' || i == 'x' || i == 'X' || i == '%')
		return (1);
	else
		return (0);
}

int	ft_precision(const char *format, int i, t_sf *flags, va_list ap)
{
	i++;
	if (format[i] == '*')
	{
		flags->precision = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->precision = 0;
		while (ft_digit(format[i]))
		{
			flags->precision = flags->precision * 10 + (format[i] - '0');
			i++;
		}
	}
	return (i);
}
