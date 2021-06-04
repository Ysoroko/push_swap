/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:09:29 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 12:16:12 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_ra(t_dl_lst *stack_to_rotate)
** ra:	Shift up all elements of the stack a by 1.
*/

void	ft_ra(t_dl_lst **stack_a, int write_ra)
{
	t_dl_lst	*first;

	if (!stack_a)
		return ;
	first = ft_dl_lst_first(*stack_a);
	ft_dl_lst_add_back(stack_a, first);
	ft_dl_lst_remove_first(stack_a);
	*stack_a = ft_dl_lst_first(*stack_a);
	if (write_ra)
		ft_putendl("ra");
}
