#include "libft.h"

static size_t	ft_getcount(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			i++;
			count++;
			while (s[i] != c)
				i++;
		}
	}	
	return (count);
}

static char	*ft_strmem(size_t size)
{
	void	*mem;

	mem = (char *)malloc(sizeof(char) * (size + 1));
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
		return (mem);
}

static char	*ft_getarray(size_t *i, const char *s, char c)
{
	size_t	size;
	size_t	j;
	char	*str;

	size = *i;
	j = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	str = ft_strmem(size - (*i));
	if (str != NULL)
	{
		while (*i < size)
		{
			str[j] = s[*i];
			j++;
			(*i)++;
		}
		return (str);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	count;
	size_t	i;
	size_t	j;

	array = NULL;
	i = 0;
	j = 0;
	count = ft_getcount(s, c);
	if (s != NULL)
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (array != NULL)
	{
		while (j < count)
		{
			while (s[i] == c)
				i++;
			if (s[i] != c)
				array[j++] = ft_getarray(&i, s, c);
		}
		array[j] == '\0';
		return (array);
	}
	return (NULL);
}
