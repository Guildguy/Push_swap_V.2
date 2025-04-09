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
