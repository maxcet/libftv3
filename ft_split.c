#include "libft.h"

static int	ft_get_count(const char *s, const char c)
{
	int		count;

	while (*s != 0)
	{
		if (*s != c)
		{
			while (*s != 0 && *s != c)
				s++;
			s--;
			count++;
		}
		s++;
	}
	return (count);
}

static int	ft_get_len(char const *s, char c, int index)
{
	int		len;

	len = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index] && s[index] != c)
	{
		index++;
		len++;
	}
	return (len);
}

static void	ft_add(char *str, const char *s, int *index, char c)
{
	int		last_index;

	last_index = 0;
	while (s[*index] && s[*index] == c)
		*index = *index + 1;
	while (s[*index] && s[*index] != c)
	{
		str[last_index] = s[*index];
		last_index++;
		*index = *index + 1;
	}
	*index = *index - 1;
	str[last_index] = '\0';
}

static char	**ft_add_words(const char *s, char c, char **words)
{
	int		char_id;
	int		word_len;
	int		arr_id;

	char_id = 0;
	arr_id = 0;
	while (s[char_id] != 0)
	{
		word_len = ft_get_len(s, c, char_id);
		if (word_len != 0)
		{
			words[arr_id] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (words == NULL)
			{
				while (arr_id--)
					free(words[arr_id]);
				free(words);
				return (NULL);
			}
			ft_add(words[arr_id], s, &char_id, c);
		}
		char_id++;
		arr_id++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;

	if (!s)
		return (NULL);
	count = ft_get_count(s, c) + 1;
	words = (char **)malloc(sizeof(char *) * count);
	if (!words)
		return (NULL);
	words[count - 1] = NULL;
	if (count == 1)
		return (words);
	words = ft_add_words(s, c, words);
	return (words);
}
