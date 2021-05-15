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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	index;

	str = ft_strmem(ft_strlen(s));
	if (s != NULL && f && str != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			str[index] = f(index, s[index]);
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
