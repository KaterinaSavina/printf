#include "ft_printf.h"

int	ft_printer_uint(int len, char *str, t_sf flags)
{
	int	n;

	n = 0;
	if (flags.precision >= 0)
		n += ft_print_w(flags.precision, len, 1);
	n += ft_print_precision(len, str);
	return (n);
}

int	ft_u_int(int len, char *str, t_sf flags)
{
	int	n;

	n = 0;
	if (flags.minus == 1)
		n += ft_printer_uint(len, str, flags);
	if (flags.precision >= 0 && flags.precision < len)
		flags.precision = len;
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		n += ft_print_w(flags.width, 0, 0);
	}
	else
		n += ft_print_w(flags.width, len, flags.zero);
	if (flags.minus == 0)
		n += ft_printer_uint(len, str, flags);
	return (n);
}

int	ft_print_uint(unsigned int i, t_sf flags)
{
	int		n;
	int		len;
	char	*str;

	n = 0;
	i = (unsigned int)(4294967295 + 1 + i);
	if (i == 0 && flags.precision == 0)
		return (ft_print_w(flags.width, 0, 0));
	str = ft_long_itoa(i);
	len = ft_strlen(str);
	n += ft_u_int(len, str, flags);
	free(str);
	return (n);
}
