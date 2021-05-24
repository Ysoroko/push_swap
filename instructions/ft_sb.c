/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:29:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 15:48:59 by ysoroko          ###   ########.fr       */
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
** void	ft_sb(t_dl_lst *stack_a)
** This function is responsible for the following operations:
** sb:	switches last two elements of the stack_b
** If the stack is empty or counts less than 2 elements, do nothing.
*/

void	ft_sb(t_dl_lst *stack_b, int write_sb)
{
	if (!stack_b || ft_dl_lst_size(stack_b) <= 1)
		return ;
	ft_swap_two_last_elements(stack_b);
	if (write_sb)
		ft_putendl("sb");
}
