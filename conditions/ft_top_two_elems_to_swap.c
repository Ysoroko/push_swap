/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_two_elems_to_swap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:04:57 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/28 14:52:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_top_two_elems_to_swap(t_dl_lst *stack, int low_to_high)
** This function returns 1 if we need to swap top and top - 1 elements
** (= perform sa or sb)
** Returns 0 otherwise
*/

int	ft_top_two_elems_to_swap(t_dl_lst *stack, int low_to_high)
{
	int	top;
	int	top_prev;

	top = (ft_dl_lst_last(stack))->content;
	top_prev = ((ft_dl_lst_last(stack))->previous)->content;
	if (low_to_high)
	{
		if (top < top_prev)
			return (1);
	}
	if (!low_to_high)
	{
		if (top > top_prev)
			return (1);
	}
	return (0);
}
