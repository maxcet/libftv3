    #include "libft.h"

    static char	**ft_malloc_error(char **tab)
    {
    	unsigned int	i;

    	i = 0;
    	while (tab[i])
    	{
    		free(tab[i]);
    		i++;
    	}
    	free(tab);
    	return (NULL);
    }

    static unsigned int	ft_get_count(char const *s, char c)
    {
    	unsigned int	i;
    	unsigned int	nb_strs;

    	if (!s[0])
    		return (0);
    	i = 0;
    	nb_strs = 0;
    	while (s[i] && s[i] == c)
    		i++;
    	while (s[i])
    	{
    		if (s[i] == c)
    		{
    			nb_strs++;
    			while (s[i] && s[i] == c)
    				i++;
    			continue ;
    		}
    		i++;
    	}
    	if (s[i - 1] != c)
    		nb_strs++;
    	return (nb_strs);
    }

    static void	ft_get_newstr(char **new_str, unsigned int *new_str_len, char c)
    {
    	unsigned int i;

    	*new_str += *new_str_len;
    	*new_str_len = 0;
    	i = 0;
    	while (**new_str && **new_str == c)
    		(*new_str)++;
    	while ((*new_str)[i])
    	{
    		if ((*new_str)[i] == c)
    			return ;
    		(*new_str_len)++;
    		i++;
    	}
    }

    char	**ft_split(char const *s, char c)
    {
    	char			**array;
    	char			*newstr;
    	unsigned int	newstrlen;
    	unsigned int	count_str;
    	unsigned int	i;

    	if (!s)
    		return (NULL);
    	count_str = ft_get_count(s, c);
    	if (!(array = (char **)malloc(sizeof(char *) * (count_str + 1))))
    		return (NULL);
    	i = 0;
    	newstr = (char *)s;
    	newstrlen = 0;
    	while (i < count_str)
    	{
    		ft_get_newstr(&newstr, &newstrlen, c);
    		if (!(array[i] = (char *)malloc(sizeof(char) * (newstrlen + 1))))
    			return (ft_malloc_error(array));
    		ft_strlcpy(array[i], newstr, newstrlen + 1);
    		i++;
    	}
    	array[i] = NULL;
    	return (array);
    }