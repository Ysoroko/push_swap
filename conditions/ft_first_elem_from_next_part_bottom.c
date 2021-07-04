/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_elem_from_next_part_bottom.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:21:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/04 15:38:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_first_elem_from_next_part_bottom(t_dl_lst *stack, int *pt, int p_ln)
** This function returns the first value encountered while starting to read
** from the bottom of stack_a that belongs to the next part of sorted stack_a
** It returns the value of the content of the element.
*/

int	ft_first_elem_from_next_prt_bottom(t_dl_lst *a, t_dl_lst *b, int *p, int l)
{
	t_dl_lst	*current;

	current = ft_dl_lst_last(a);
	while (current != a->previous && (!ft_elem_is_in_next_part(current, p, l)
			|| (ft_elem_is_in_next_part(current, p, l)
				&& ft_dl_lst_search_elem(b, current->content))))
	{
		current = current->previous;
	}
	if (!current)
		return (0);
	return (current->content);
}
