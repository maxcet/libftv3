#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	fin_len;

	dst_len = ft_strlen(dst);
	if (size < dst_len)
		fin_len = ft_strlen(src) + size;
	else
		fin_len = ft_strlen(src) + dst_len;
	if (size > dst_len)
	{
		dst = dst + dst_len;
		size = size - dst_len;
		while (*src && size-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (fin_len);
}
