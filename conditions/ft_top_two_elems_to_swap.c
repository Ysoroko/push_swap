/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_two_elems_to_swap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:04:57 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/11 14:22:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_top_two_elems_to_swap(t_dl_lst *stack_a, int low_to_high)
** This function returns 1 if we need to swap top and top - 1 elements
** (= perform sa or sb)
** Returns 0 otherwise
** top of stack_a = lowest value
*/

int	ft_top_two_elems_to_swap(t_dl_lst *stack_a)
{
	int	top;
	int	top_next;

	if (!stack_a || !stack_a->next)
		return (0);
	top = stack_a->content;
	top_next = (stack_a->next)->content;
	if (top > top_next)
		return (1);
	return (0);
}
