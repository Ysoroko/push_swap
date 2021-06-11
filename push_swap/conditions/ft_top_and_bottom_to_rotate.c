/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_and_bottom_to_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:19:03 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/11 14:24:12 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_top_and_bottom_to_rotate(t_dl_lst *stack_a)
** This function is used to check if we need to swap the top and the bottom
** of the stack_a
** Returns 1 if we do, 0 if we don't
*/

int	ft_top_and_bottom_to_rotate(t_dl_lst *stack_a)
{
	int	top;
	int	bottom;

	if (!stack_a || !stack_a->next)
		return (0);
	top = stack_a->content;
	bottom = ft_dl_lst_last(stack_a)->content;
	if (bottom < top)
		return (1);
	return (0);
}
