#include	"ft_printf.h"

int	ft_print_c(char c, t_sf flags)
{
	int	n;

	n = 0;
	if (flags.minus == 1)
		n += ft_putchar(c);
	n += ft_print_w(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		n += ft_putchar(c);
	return (n);
}

int	ft_printer_str(t_sf flags, char *str, int len)
{
	int	n;

	n = 0;
	if (flags.precision >= 0)
	{
		n += ft_print_w(flags.precision, len, 0);
		n += ft_print_precision(flags.precision, str);
	}
	else
		n += ft_print_precision(len, str);
	return (n);
}

int	ft_print_str(char *str, t_sf flags)
{
	int	n;
	int	len;

	n = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision > len)
		flags.precision = len;
	if (flags.minus == 1)
		n += ft_printer_str(flags, str, len);
	if (flags.precision >= 0)
		n += ft_print_w(flags.width, flags.precision, 0);
	else
		n += ft_print_w(flags.width, len, 0);
	if (flags.minus == 0)
		n += ft_printer_str(flags, str, len);
	return (n);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_do_string(unsigned long long tmp, int i, char *str, t_sf flags)
{
	i--;
	while (tmp != 0)
	{
		if ((tmp % flags.base) < 10)
			str[i] = (tmp % flags.base) + 48;
		else
			str[i] = (tmp % flags.base) + 87;
		tmp /= flags.base;
		i--;
	}
	return (str);
}
