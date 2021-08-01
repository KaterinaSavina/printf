#include "libft.h"

int	ft_toupper(int x)
{
	if ((x >= 97) && (x < 123))
		return (x - 32);
	else
		return (x);
}
