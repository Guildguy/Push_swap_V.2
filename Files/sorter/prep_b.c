/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:17:18 by fleite-j          #+#    #+#             */
/*   Updated: 2025/03/05 10:17:20 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*a;
	t_node	*target;
	long	largest;

	while (stack_b)
	{
		largest = LONG_MAX;
		a = stack_a;
		while (a)
		{
			if (a->n > stack_b->n && a->n < largest)
			{
				largest = a->n;
				target = a;
			}
			a = a->next;
		}
		if (largest == LONG_MAX)
			stack_b->target = find_smallest(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	prepare_b(t_node *stack_a, t_node *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_b(stack_a, stack_b);
}
