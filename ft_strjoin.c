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

static char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (dest[index] != '\0')
	{
		index++;
	}
	while (src[index2] != '\0')
	{
		dest[index + index2] = src[index2];
		index2++;
	}
	dest[index + index2] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (s1 != NULL && s2 != NULL)
	{
		dest = ft_strmem(ft_strlen(s1) + ft_strlen(s2));
		if (dest == NULL)
			return (NULL);
		ft_strcpy(dest, s1);
		ft_strcat(dest, s2);
		return (dest);
	}
	else
		return (NULL);
}
