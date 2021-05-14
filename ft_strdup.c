#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1);
	str = (char*)malloc(len + 1);
	if (str == 0)
		return (0);
	len = 0;
	while (s1[len] != 0)
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
