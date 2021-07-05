/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:59:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/05 14:55:52 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rrb(t_dl_lst *stack_to_rotate)
** rrb:	Shift down all elements of the stack a by 1.
**			The last element becomes the first one.
*/

int	ft_rrb(t_dl_lst **stack_b, int write_rrb)
{
	t_dl_lst	*first;
	t_dl_lst	*last;
	t_dl_lst	*before_last;

	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return (0);
	first = *stack_b;
	last = ft_dl_lst_last(*stack_b);
	*stack_b = last;
	before_last = last->previous;
	last->next = first;
	last->previous = 0;
	first->previous = last;
	before_last->next = 0;
	if (write_rrb)
		ft_putendl("rrb", STDOUT);
	return (1);
}
