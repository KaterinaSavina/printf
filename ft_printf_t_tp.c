#include "ft_printf.h"

t_sf	ft_hex(t_sf flags, char c)
{
	flags.type = c;
	if (c == 'X')
		flags.hex = 1;
	return (flags);
}

t_sf	ft_star(t_sf flags, va_list ap)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width = -flags.width;
	}
	return (flags);
}

t_sf	ft_width(t_sf flags, char c)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = flags.width * 10 +(c - '0');
	return (flags);
}

t_sf	ft_minus(t_sf type)
{
	type.minus = 1;
	type.zero = 0;
	return (type);
}
