#include "ft_printf.h"

int	ft_print_w(int width, int min, int x)
{
	int	n;

	n = 0;
	while (width - min > 0)
	{
		if (x)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		n++;
	}
	return (n);
}

int	ft_print_precision(int precision, char *str)
{
	int	n;

	n = 0;
	while (str[n] && n < precision)
	{
		ft_putchar(str[n]);
		n++;
	}
	return (n);
}

char	*ft_str_maker(unsigned long long t, t_sf flags)
{
	unsigned long long	tmp;
	char				*str;
	int					i;

	i = 0;
	str = 0;
	tmp = t;
	if (t == 0)
		return (ft_strdup("0"));
	while (t != 0)
	{
		t /= flags.base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	str = ft_do_string(tmp, i, str, flags);
	return (str);
}

void	ft_init_flags(t_sf *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->star = 0;
	flags->base = 16;
	flags->hex = 0;
}
