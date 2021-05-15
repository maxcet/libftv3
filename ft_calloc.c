#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*mem;

	mem = (void *)malloc(number * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, number * size);
	return (mem);
}
