#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;
	unsigned char simbol;

	str = (unsigned char *)b;
	simbol = (unsigned char)c;
	while (len != 0)
	{
		*str = simbol;
		*str++;
		len--; 
	}
	return (b);
}
