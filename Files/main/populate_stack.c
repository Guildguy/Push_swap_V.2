/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:30:41 by fleite-j          #+#    #+#             */
/*   Updated: 2025/02/24 18:30:43 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static bool	check_args(char *arg)
{
	if (!((*arg == '+' || *arg == '-') || (*arg >= '0' && *arg <= '9')))
		return (false);
	if ((*arg == '+' || *arg == '-') && (!(arg[1] >= '0' && arg[1] <= '9')))
		return (false);
	while (*++arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (false);
	}
	return (true);
}

static bool	check_dup(t_node *stack, int n)
{
	if (!stack)
		return (true);
	while (stack)
	{
		if (stack->n == n)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static void	add_node(t_node **stack, int n)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->n = n;
	new_node->shortest = false;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		new_node->prev = last_node;
		last_node->next = new_node;
	}
}

static void	error_handler(t_node **stack, char **ptr, bool array)
{
	deallocate_node(stack);
	if (array)
		free_matrix(ptr);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	populate_stack(t_node **stack, char **ptr, bool array)
{
	long	n;
	int		i;

	i = 0;
	if (!ptr[i])
		error_handler(stack, ptr, array);
	while (ptr[i])
	{
		if (!check_args(ptr[i]))
			error_handler(stack, ptr, array);
		n = ft_atol(ptr[i]);
		if (n > 2147483647 || n < -2147483648)
			error_handler(stack, ptr, array);
		if (!check_dup(*stack, (int)n))
			error_handler(stack, ptr, array);
		add_node(stack, (int)n);
		i++;
	}
	if (array)
		free_matrix(ptr);
}
