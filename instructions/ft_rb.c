/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:09:29 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 12:16:16 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_ra_rb(t_dl_lst *stack_to_rotate)
** ra/rb:	Shift up all elements of the stack by 1.
**			The first element becomes the last one.
*/

void	ft_rb(t_dl_lst **stack_b, int write_rb)
{
	t_dl_lst	*first;

	if (!stack_b)
		return ;
	first = ft_dl_lst_first(*stack_b);
	ft_dl_lst_add_back(stack_b, first);
	ft_dl_lst_remove_first(stack_b);
	*stack_b = ft_dl_lst_first(*stack_b);
	if (write_rb)
		ft_putendl("rb");
}
