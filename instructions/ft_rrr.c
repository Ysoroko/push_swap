/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:05:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 15:50:20 by ysoroko          ###   ########.fr       */
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
	ft_rra(stack_a, 0);
	ft_rra(stack_b, 0);
	ft_putendl("rrr");
}
