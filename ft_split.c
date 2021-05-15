#include "libft.h"

static char	**ft_malloc_error(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static unsigned int	ft_get_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	ft_get_newstr(char **new_str, unsigned int *new_str_len, char c)
{
	unsigned int	i;

	*new_str += *new_str_len;
	*new_str_len = 0;
	i = 0;
	while (**new_str && **new_str == c)
		(*new_str)++;
	while ((*new_str)[i])
	{
		if ((*new_str)[i] == c)
			return ;
		(*new_str_len)++;
		i++;
	}
}

static char	*ft_malloc(size_t size)
{
	char	*dst;

	dst = ((char *)malloc(sizeof(char) * (size + 1)));
	if (dst == NULL)
		return (ft_malloc_error(dst));
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	char			*newstr;
	unsigned int	newstrlen;
	unsigned int	count_str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	count_str = ft_get_count(s, c);
	array = (char **)malloc(sizeof(char *) * (count_str + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	newstr = (char *)s;
	newstrlen = 0;
	while (i < count_str)
	{
		ft_get_newstr(&newstr, &newstrlen, c);
		array[i] = ft_malloc(newstrlen);
		ft_strlcpy(array[i], newstr, newstrlen + 1);
		i++;
	}
	array[i] = '\0';
	return (array);
}
