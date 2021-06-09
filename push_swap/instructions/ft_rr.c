/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:21:11 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 14:49:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rr(t_dl_lst *stack_a, t_dl_lst *stack_b)
** rr:	Shift up all elements of both stacks by 1.
**		The first element becomes the last one.
*/

void	ft_rr(t_dl_lst **stack_a, t_dl_lst **stack_b, int write_rr)
{
	if (stack_a && stack_b)
	{
		ft_ra(stack_a, 0);
		ft_rb(stack_b, 0);
		if (write_rr)
			ft_putendl("rr");
	}
}
