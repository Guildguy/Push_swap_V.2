/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:01:04 by fleite-j          #+#    #+#             */
/*   Updated: 2025/02/25 18:01:05 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*static int	count_word(char *str, char separator)
{
	int		i;
	int		count;
	bool	inside_word;

	i = 0;
	count = 0;
	while (str[i])
	{
		inside_word = false;
		while (str[i] == separator && str[i])
			++i;
		while (str[i] != separator && str[i])
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++i;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**push_split(char *str, char separator)
{
	int		i;
	int		word_nbr;
	char	**vector_str;

	i = 0;
	word_nbr = count_word(str, separator);
	if (!word_nbr)
		exit(1);
	vector_str = malloc(sizeof(char *) * (size_t)(word_nbr + 2));
	if (vector_str == NULL)
		return (NULL);
	while (word_nbr-- >= 0)
	{
		if (i == 0)
		{
			vector_str[i] = malloc(sizeof(char));
			if (vector_str[i] == NULL)
				return (NULL);
			vector_str[i++][0] = '\0';
			continue ;
		}
		vector_str[i++] = get_next_word(str, separator);
	}
	vector_str[i] = NULL;
	return (vector_str);
}*/

static int	count_words(const char *s, char c)
{
	int	count;
	int	index;
	int	len_s;

	len_s = ft_strlen(s);
	if (len_s == 0)
		return (0);
	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != (unsigned char)c)
		{
			while (s[index] != (unsigned char)c && s[index] != '\0')
				index++;
			count++;
		}
		if (s[index] != '\0')
			index++;
	}
	return (count);
}

static int	free_memory(char ***str_list, int allocated)
{
	int	index;

	if (!str_list || !*str_list)
		return (0);
	index = 0;
	while (index < allocated)
	{
		free((*str_list)[index]);
		index++;
	}
	free(*str_list);
	*str_list = NULL;
	return (0);
}

void	free_matrix(char *av[])
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[++i])
		free (av[i]);
	free(av);
}

static int	fill_arr(int size, const char *s, char c, char ***str_list)
{
	int		counter;
	int		index;
	int		pass;
	char	*test;

	index = 0;
	counter = 0;
	while (s[index] != '\0' && counter < size)
	{
		pass = 0;
		while (s[index] == (unsigned char)c)
			index++;
		while (s[index + pass] && s[index + pass] != c)
			pass++;
		test = ft_substr(&s[index], 0, pass);
		if (!test)
			return (free_memory(str_list, counter));
		(*str_list)[counter] = test;
		counter++;
		index += pass;
	}
	(*str_list)[size] = NULL;
	return (1);
}

char	**push_split(char const *str, char separator)
{
	int		size;
	char	**str_list;

	if (!str)
		return (ft_calloc(1, sizeof(char *)));
	size = count_words(str, separator);
	if (size == 0)
		return (ft_calloc(1, sizeof(char *)));
	str_list = (char **) ft_calloc((size + 1), sizeof(char *));
	if (str_list == 0)
		return (0);
	if (!fill_arr(size, str, separator, &str_list))
	{
		free(str_list);
		return (NULL);
	}
	return (str_list);
}
