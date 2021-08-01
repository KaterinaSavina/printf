#include "ft_printf.h"

int	ft_zero_ptr(t_sf flags)
{
	int	i;

	i = 0;
	if (flags.width >= 0 && flags.minus == 0)
	{
		i += ft_print_w(flags.width, 2, 0);
		i += ft_print_precision(2, "0x");
	}
	else
	{
		i += ft_print_precision(2, "0x");
		i += ft_print_w(flags.width, 2, 0);
	}
	return (i);
}

int	ft_ptr(int len, char *ptr, t_sf flags)
{
	int	n;

	n = 0;
	n += ft_print_precision(2, "0x");
	if (flags.precision >= 0)
	{
		n += ft_print_w(flags.precision, len, 1);
		n += ft_print_precision(flags.precision, ptr);
	}
	else
		n += ft_print_precision(len, ptr);
	return (n);
}

int	ft_ptr_printer(int n, int len, char *ptr, t_sf flags)
{
	if (flags.precision < len)
		flags.precision = len;
	if (flags.minus == 1 && flags.precision <= 0)
	{
		n += ft_ptr(len, ptr, flags);
		n += ft_print_w(flags.width, len + 2, 0);
	}
	if (flags.minus == 1 && flags.precision > 0)
	{
		n += ft_ptr(len, ptr, flags);
		n += ft_print_w(flags.width, flags.precision + 2, 0);
	}
	if (flags.minus == 0 && flags.precision > 0)
	{
		n += ft_print_w(flags.width, flags.precision + 2, 0);
		n += ft_ptr(len, ptr, flags);
	}
	if (flags.minus == 0 && flags.precision <= 0)
	{
		n += ft_print_w(flags.width, len + 2, 0);
		n += ft_ptr(len, ptr, flags);
	}
	return (n);
}

int	ft_print_p(unsigned long long p, t_sf flags)
{
	int		n;
	int		len;
	char	*ptr;

	n = 0;
	if (p == 0 && flags.precision == 0)
		return (ft_zero_ptr(flags));
	ptr = ft_str_maker(p, flags);
	len = ft_strlen(ptr);
	n += ft_ptr_printer(n, len, ptr, flags);
	free(ptr);
	return (n);
}
