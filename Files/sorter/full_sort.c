/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:22 by fleite-j          #+#    #+#             */
/*   Updated: 2025/03/05 10:16:46 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	move_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*shortest;

	shortest = get_shortest(*stack_a);
	if (shortest->upper_part && shortest->target->upper_part)
		rotate_a_b(stack_a, stack_b, shortest);
	else if (!(shortest->upper_part) && !(shortest->target->upper_part))
		reverse_a_b(stack_a, stack_b, shortest);
	set_top_a(stack_a, shortest);
	set_top_b(stack_b, shortest->target);
	pb(stack_a, stack_b);
}

static void	move_b(t_node **stack_a, t_node **stack_b)
{
	set_top_a(stack_a, (*stack_b)->target);
	pa(stack_b, stack_a);
}

static void	order_values(t_node **stack)
{
	t_node	*smallest;

	smallest = find_smallest(*stack);
	while ((*stack)->n != smallest->n)
	{
		if (smallest->upper_part)
			ra(stack);
		else
			rra(stack);
	}
}

void	full_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len-- > 3 && !stack_done(*stack_a))
		pb(stack_a, stack_b);
	if (len-- > 3 && !stack_done(*stack_a))
		pb(stack_a, stack_b);
	while (len-- > 3 && !stack_done(*stack_a))
	{
		prepare_a(*stack_a, *stack_b);
		move_a(stack_a, stack_b);
	}
	small_sort(stack_a);
	while (*stack_b)
	{
		prepare_b(*stack_a, *stack_b);
		move_b(stack_a, stack_b);
	}
	set_position(*stack_a);
	order_values(stack_a);
}
