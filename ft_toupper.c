#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_toupper(int c)
{
	if (ft_islower(c) == 1)
		c = c - 'a' + 'A';
	return (c);
}
