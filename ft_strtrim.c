#include "libft.h"

static int	ft_getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(s1);
	index = 0;
	while (index < len)
	{
		if (ft_strchr(set, s1[index]) == 0)
			break ;
		index++;
	}
	return (index);
}

static int	ft_getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(s1);
	index = 0;
	while (index < len)
	{
		if (ft_strchr(set, s1[len - index - 1]) == 0)
			break ;
		index++;
	}
	return (len - index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*newstr;
	size_t		start;
	size_t		finish;

	newstr = NULL;
	if (s1 != NULL && set == NULL)
		newstr = ft_strdup(s1);
	else if (s1 != NULL)
	{
		start = ft_getstart(s1, set);
		finish = ft_getend(s1, set);
		if (start >= finish)
			return (ft_strdup(""));
		newstr = (char *)malloc(sizeof(char) * (finish - start + 1) + 1);
		if (newstr == NULL)
			return (NULL);
		ft_strlcpy(newstr, s1 + start, finish - start + 1);
	}
	return (newstr);
}
