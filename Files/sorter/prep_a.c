/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:57 by fleite-j          #+#    #+#             */
/*   Updated: 2025/03/05 10:17:01 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*b;
	t_node	*target;
	long	smallest;

	while (stack_a)
	{
		smallest = LONG_MIN;
		b = stack_b;
		while (b)
		{
			if (b->n < stack_a->n && b->n > smallest)
			{
				smallest = b->n;
				target = b;
			}
			b = b->next;
		}
		if (smallest == LONG_MIN)
			stack_a->target = find_largest(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

static void	set_cost(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->pos;
		if (!(stack_a->upper_part))
			stack_a->cost = len_a - (stack_a->pos);
		if (stack_a->target->upper_part)
			stack_a->cost += stack_a->target->pos;
		else
			stack_a->cost += len_b - (stack_a->target->pos);
		stack_a = stack_a->next;
	}
}

static void	set_shortest(t_node *stack)
{
	long	shortest;
	t_node	*node;

	if (!stack)
		return ;
	shortest = LONG_MAX;
	while (stack)
	{
		if (stack->cost < shortest)
		{
			node = stack;
			shortest = stack->cost;
		}
		stack = stack->next;
	}
	node->shortest = true;
}

void	set_position(t_node *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (!stack)
		return ;
	mid = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= mid)
			stack->upper_part = true;
		else
			stack->upper_part = false;
		stack = stack->next;
		i++;
	}
}

void	prepare_a(t_node *stack_a, t_node *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_a(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_shortest(stack_a);
}
