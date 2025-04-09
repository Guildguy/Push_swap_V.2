/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:20:28 by fleite-j          #+#    #+#             */
/*   Updated: 2025/02/13 17:20:30 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int c, char *v[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (c == 1)
		return (0);
	else if (c == 2)
		v = push_split(v[1], ' ');
	populate_stack(&a, (v + !(c == 2)), c == 2);
	if (!stack_done(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			small_sort(&a);
		else
			full_sort(&a, &b);
	}
	deallocate_node(&a);
	return (0);
}
