/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:05:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 14:33:43 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rr(t_dl_lst *stack_a, t_dl_lst *stack_b)
** rrr:	Shift down all elements of both stacks by 1.
**		The last element becomes the first one.
*/

void	ft_rrr(t_dl_lst *stack_a, t_dl_lst *stack_b)
{
	ft_rra_rrb(stack_a);
	ft_rra_rrb(stack_b);
}
