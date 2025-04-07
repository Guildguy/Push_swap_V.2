/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:00:35 by fleite-j          #+#    #+#             */
/*   Updated: 2025/02/25 18:00:38 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*list;

	if (!lst)
		return (NULL);
	list = lst;
	while (list->next)
		list = list->next;
	return (list);
}
