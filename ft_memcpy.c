#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *str;
	unsigned char *symbol;

	str = (unsigned char *)dst;
	symbol = (unsigned char *)src;
	while (n != 0)
	{
		*str = *symbol;
		*symbol++;
		*str++;
		n--; 
	}
	return (dst);
}
