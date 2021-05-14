#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		minus;
	char	*temp;

	result = 0;
	minus = 1;
	temp = str;
	while ((*temp >= 9 && *temp <= 13) || (*temp == ' '))
		temp++;
	
	if (*temp == '-')
			minus *= -1;
	while (minus == -1 || *temp == '+')
		temp++;
	
	while (ft_isdigit(*temp))
	{
		result = result * 10 + (*temp - '0');
		temp++;
	}
	return (result * minus);
}
