#include "libft.h"

int	ft_digit(int x)
{
	if ((x >= 48) && (x < 58))
		return (1);
	else
		return (0);
}
