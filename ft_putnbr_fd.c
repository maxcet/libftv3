#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char m;

	m = '-';
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd(m, fd);
		ft_putnbr_fd(-n, fd);
	}
}
