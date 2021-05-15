#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	symbol;

	str = (char *)s + ft_strlen(s);
	symbol = (char)c;
	while (str >= s)
	{
		if (*str == symbol)
			return (str);
		str--;
	}
	return (NULL);
}
