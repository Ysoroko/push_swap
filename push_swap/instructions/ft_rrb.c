/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:59:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 13:50:10 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rrb(t_dl_lst *stack_to_rotate)
** rrb:	Shift down all elements of the stack a by 1.
**			The last element becomes the first one.
*/

void	ft_rrb(t_dl_lst **stack_b, int write_rrb)
{
	t_dl_lst	*last;

	if (!stack_b)
		return ;
	last = ft_dl_lst_last(*stack_b);
	ft_dl_lst_add_front(stack_b, last);
	ft_dl_lst_remove_last(stack_b);
	*stack_b = last;
	if (write_rrb)
		ft_putendl("rrb");
}
