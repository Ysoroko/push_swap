/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_vs_bottom_to_swap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:01:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 11:07:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_top_vs_bottom_to_swap(t_dl_lst *stack, int low_to_high)
** This function returns 1 if we need to swap top and bottom
** (= perform ra/rb/rra/rrb)
** Returns 0 otherwise
*/

int	ft_top_vs_bottom_to_swap(t_dl_lst *stack, int low_to_high)
{
	int	top;
	int	bottom;

	top = (ft_dl_lst_last(stack))->content;
	bottom = (ft_dl_lst_first(stack))->content;
	if (low_to_high)
	{
		if (top < bottom)
			return (1);
	}
	if (!low_to_high)
	{
		if (top > bottom)
			return (1);
	}
	return (0);
}