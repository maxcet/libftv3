char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (dest[index] != '\0')
	{
		index++;
	}
	while (src[index2] != '\0' && index2 < nb)
	{
		dest[index] = src[index2];
		index++;
		index2++;
	}
	dest[index2] = 0;
	return (dest);
}
