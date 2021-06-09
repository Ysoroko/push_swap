/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:09:29 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 13:51:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_ra(t_dl_lst *stack_to_rotate)
** ra:	Shift up all elements of the stack a by 1.
** The first element becomes the last one
*/

void	ft_ra(t_dl_lst **stack_a, int write_ra)
{
	t_dl_lst	*last;
	t_dl_lst	*first;
	t_dl_lst	*second;

	if (!stack_a || !*stack_a)
		return ;
	last = ft_dl_lst_last(*stack_a);
	first = *stack_a;
	second = first->next;
	last->next = first;
	first->next = 0;
	first->previous = last;
	second->previous = 0;
	*stack_a = second;
	if (write_ra)
		ft_putendl("ra");
}
