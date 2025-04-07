/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:15:20 by fleite-j          #+#    #+#             */
/*   Updated: 2025/03/05 10:15:22 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last_node;

	last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	(*stack)->prev = last_node;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
}

void	rra(t_node **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_node **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
