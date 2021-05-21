/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:29:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 14:33:43 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** static void	ft_swap_two_last_elements(t_dl_lst *stack)
** This function takes the last 2 elements of the stack and swaps them
*/

static void	ft_swap_two_last_elements(t_dl_lst *stack)
{
	t_dl_lst	*element_to_swap_1;
	t_dl_lst	*element_to_swap_2;

	element_to_swap_1 = ft_dl_lst_last(stack);
	element_to_swap_2 = (ft_dl_lst_last(stack))->previous;
	ft_dl_lst_swap(element_to_swap_1, element_to_swap_2);
}

/*
** void	ft_sa_sb_ss(t_dl_lst *stack_a, t_dl_lst *stack_b)
** This function is responsible for the following operations:
** sa:	switches last two elements of the stack_a
** sb:	switches last two elements of the stack_b
** If the stack is empty or counts less than 2 elements, do nothing.
*/

void	ft_sa_sb(t_dl_lst *stack)
{
	if (!stack || ft_dl_lst_size(stack) <= 1)
		return ;
	ft_swap_two_last_elements(stack);
}
