/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:59:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 12:08:58 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rra_rrb(t_dl_lst *stack_to_rotate)
** ra/rb:	Shift down all elements of the stack by 1.
**			The last element becomes the first one.
*/

void	ft_rra_rrb(t_dl_lst *stack_to_rotate)
{
	t_dl_lst	*last;

	last = ft_dl_lst_last(stack_to_rotate);
	ft_dl_lst_add_front(stack_to_rotate, last);
	ft_dl_lst_remove_last(stack_to_rotate);
}
