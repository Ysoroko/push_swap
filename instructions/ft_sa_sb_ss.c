/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:29:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 16:47:24 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
** ss:	switches last two elements of both stack_a and stack_b
** If there is no stack_b argument , but there is stack_b argument, we do "sa"
** If there is no stack_a argument , but there is stack_b argument, we do "sb"
** If there are both stack_a and stack_b arguments, we do "ss"
*/

void	ft_sa_sb_ss(t_dl_lst *stack_a, t_dl_lst *stack_b)
{
	if (!stack_a && !stack_b)
		return ;
	if (stack_a && !stack_b)
		ft_swap_two_last_elements(stack_a);
	else if (stack_b && !stack_a)
		ft_swap_two_last_elements(stack_b);
	else
	{
		ft_swap_two_last_elements(stack_a);
		ft_swap_two_last_elements(stack_b);
	}
}
