#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	symbol;

	str = (char *)s;
	symbol = (char)c;
	while (*str && (*str != symbol))
		str++;
	if (*str == symbol)
		return (str);
	else
		return (NULL);
}
