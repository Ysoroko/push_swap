/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_elem_from_next_part_bottom.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:21:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/01 14:22:46 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_first_elem_from_next_part_bottom(t_dl_lst *stack, int *pt, int p_ln)
** This function returns the first value encountered while starting to read
** from the bottom of stack_a that belongs to the next part of sorted stack_a
** It returns the value of the content of the element.
*/

int	ft_first_elem_from_next_part_bottom(t_dl_lst *stack_a, int *part, int p_ln)
{
	t_dl_lst	*current;

	current = ft_dl_lst_last(stack_a);
	while (current && !ft_elem_is_in_next_part(current, part, p_ln))
	{
		current = current->previous;
	}
	if (!current)
		return (0);
	return (current->content);
}