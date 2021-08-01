#include "ft_printf.h"

int	ft_printer_hex(int len, char *str, t_sf flags)
{
	int	n;

	n = 0;
	if (flags.precision >= 0)
		n +=ft_print_w(flags.precision, len, 1);
	n += ft_print_precision(len, str);
	return (n);
}

int	ft_change_hex(int len, char *str, t_sf flags)
{
	int	n;

	n = 0;
	if (flags.minus == 1)
		n += ft_printer_hex(len, str, flags);
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
		n += ft_printer_hex(len, str, flags);
	return (n);
}

int	ft_print_h(unsigned int hex, t_sf flags)
{
	int		i;
	int		len;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	hex = (unsigned int)(4294967295 + 1 + hex);
	if (hex == 0 && flags.precision == 0)
		return (ft_print_w(flags.width, 0, 0));
	str = ft_str_maker((unsigned long long)hex, flags);
	if (flags.hex)
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	len = ft_strlen(str);
	n += ft_change_hex(len, str, flags);
	free(str);
	return (n);
}
