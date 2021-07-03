/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_elem_from_next_part_top.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:48:36 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/03 15:34:54 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_first_elem_from_next_part_top(t_dl_lst *stack, int *part, int p_len)
** This function returns the first value encountered while starting to read
** from the top of stack_a that belongs to the next part of sorted stack_a
** It returns the value of the content of the element.
*/

int	ft_first_elem_from_next_part_top(t_dl_lst *a, t_dl_lst *b, int *prt, int l)
{
	t_dl_lst	*current;

	current = a;
	while (current && (!ft_elem_is_in_next_part(current, prt, l) ||
			(ft_elem_is_in_next_part(current, prt, l) &&
			ft_dl_lst_search_elem(b, current->content))))
	{
		current = current->next;
	}
	if (!current)
	{
		return (0);
	}
	return (current->content);
}
