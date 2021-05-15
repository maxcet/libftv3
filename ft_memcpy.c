#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*symbol;

	str = (unsigned char *)dst;
	symbol = (unsigned char *)src;
	if (dst == NULL && src == NULL && n > 0)
		return (NULL);
	while (n--)
		*str++ = *symbol++;
	return (dst);
}
