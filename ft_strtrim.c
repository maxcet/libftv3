#include "libft.h"

static int	ft_get_it(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*newstr;
	size_t		start;
	size_t		finish;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(""));
	start = 0;
	finish = ft_strlen(s1);
	while (ft_get_it(s1[start], set) == 0)
		start++;
	if (start == finish)
	{
		newstr = ft_strdup("");
		if (newstr == NULL)
			return (NULL);
		else
			return (newstr);
	}
	while (ft_get_it(s1[finish - 1], set) == 0)
		finish--;
	newstr = ft_substr(s1, start, finish - start);
	return (newstr);
}
