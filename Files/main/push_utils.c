/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:21:03 by fleite-j          #+#    #+#             */
/*   Updated: 2025/02/13 17:21:05 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	deallocate_node(t_node **stack)
{
	t_node	*aux;

	while (*stack)
	{
		aux = *stack;
		*stack = aux->next;
		free(aux);
	}
}

bool	stack_done(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->n > stack->next->n)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_node	*find_smallest(t_node *stack)
{
	t_node	*node;
	long	min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->n < min)
		{
			min = stack->n;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_node	*find_largest(t_node *stack)
{
	t_node	*node;
	long	max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->n > max)
		{
			max = stack->n;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_node	*get_shortest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->shortest)
			return (stack);
		else
			stack = stack->next;
	}
	return (NULL);
}
