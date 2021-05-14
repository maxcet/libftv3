#include "libft.h"

static char	*ft_strmem(size_t size)
{
	void	*mem;

	mem = (char *)malloc(sizeof(char) * (size + 1));
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
		return (mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	if (s == 0 || start + len > ft_strlen(s))
		return (NULL);
	str = ft_strmem(len);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}
