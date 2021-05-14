#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *source;
	unsigned char *dest;
	
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dest >= source)
	{
		source += len;
		dest += len;
		while (len--)
			*(--dest) = *(--source);
	}
	else
		while (len--)
			*(dest++) = *(source++);
	return (dst);
}
