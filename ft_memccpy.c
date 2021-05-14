#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*source;
	unsigned char	symbol;
	size_t			i;

	i = 0;
	str = (unsigned char *)dst;
	source = (unsigned char *)src;
	symbol = (unsigned char)c;
	while (i < n)
	{
		*(str + i) = *(source + i);
		if (source[i] == symbol)
			return (str + i + 1);
		i++; 
	}
	return (NULL);
}
