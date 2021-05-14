#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size > 0)
	{
		while (src[count] && count < (size - 1))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	count = ft_strlen(src);
	return (count);
}
