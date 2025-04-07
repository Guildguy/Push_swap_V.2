/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:17:30 by fleite-j          #+#    #+#             */
/*   Updated: 2025/03/05 10:17:32 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	small_sort(t_node **stack)
{
	t_node	*largest;

	largest = find_largest(*stack);
	if (largest == *stack)
		ra(stack);
	else if (largest == (*stack)->next)
		rra(stack);
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}
