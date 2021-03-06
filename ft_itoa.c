#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_min(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	int		numlen;
	int		minus;
	int		digit;
	char	*str;

	if (n < 0)
		minus = 1;
	else
		minus = 0;
	numlen = ft_numlen(n) + minus;
	str = (char *)malloc(numlen + 1);
	if (str)
	{
		str[numlen] = '\0';
		numlen--;
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = ft_min(digit) + '0';
			n = n / 10;
		}
		if (minus == 1)
			str[0] = '-';
	}
	return (str);
}
