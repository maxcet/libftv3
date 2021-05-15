#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			need_len;
	size_t			hays_len;
	size_t			i;
	size_t			j;
	char			*hays;

	hays = (char *)haystack;
	need_len = ft_strlen(needle);
	hays_len = ft_strlen(haystack);
	if (need_len == 0)
		return (hays);
	if (need_len > hays_len || len < need_len)
		return (NULL);
	i = 0;
	while (hays[i] != 0 && i <= len - need_len)
	{
		j = 0;
		while (needle[j] != 0 && needle[j] == haystack[i + j])
			j++;
		if (j == need_len)
			return (&hays[i]);
		i++;
	}
	return (NULL);
}
