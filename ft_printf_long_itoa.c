#include "ft_printf.h"

static int	ft_len(long tmp)
{
	int	i;

	i = 0;
	if (tmp <= 0)
		i++;
	while (tmp != 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

static char	*ft_changer(char *str, long tmp, int l)
{
	if (tmp == 0)
		str[0] = '0';
	str[l] = '\0';
	if (tmp < 0)
	{
		str[0] = '-';
		tmp = -tmp;
	}
	while (tmp)
	{
		--l;
		str[l] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (str);
}

char	*ft_long_itoa(long t)
{
	char	*str;
	int		l;
	long	tmp;

	tmp = t;
	l = ft_len(tmp);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	return (str = ft_changer(str, tmp, l));
}
