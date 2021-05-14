#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	symbol;

	str = (char *)s + ft_strlen(s);
	symbol = (char)c;
	while (str >= s && (*str != symbol))
		str--;
	if (*str == symbol)
		return (str);
	else
		return (NULL);
}
