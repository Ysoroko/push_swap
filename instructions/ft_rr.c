/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:21:11 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 12:08:03 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rr(t_dl_lst *stack_a, t_dl_lst *stack_b)
** rr:	Shift up all elements of both stacks by 1.
**		The first element becomes the last one.
*/

void	ft_rr(t_dl_lst *stack_a, t_dl_lst *stack_b)
{
	ft_ra_rb(stack_a);
	ft_ra_rb(stack_b);
}
