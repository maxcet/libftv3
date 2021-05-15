#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	symbol;

	str = (unsigned char *)b;
	symbol = (unsigned char)c;
	while (len != 0)
	{
		*str++ = symbol;
		len--;
	}
	return (b);
}
