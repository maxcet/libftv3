#include "libft.h"

static int	ft_check(char c)
{
	if (c == '-')
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	unsigned int		result;
	int		minus;
	char	*temp;

	result = 0;
	minus = 1;
	temp = (char *)str;
	while ((*temp >= 9 && *temp <= 13) || (*temp == ' '))
		temp++;
	if (*temp == '-')
		minus *= -1;
	if (*temp == '-' || *temp == '+')
	{
		if (*temp == '-')
			minus = -1;
		temp++;
	}
	while (ft_isdigit(*temp))
	{
		result = (result * 10) + (*temp - '0');
		temp++;
	}
	if (result > 2147483648)
		return (ft_check(str[0]));
	return (result * minus);
}
