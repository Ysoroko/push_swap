/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:00:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 10:04:49 by ysoroko          ###   ########.fr       */
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
** void	ft_sa(t_dl_lst *stack_a)
** This function is responsible for the following operations:
** sa:	switches last two elements of the stack_a
** If the stack is empty or counts less than 2 elements, do nothing.
*/

void	ft_sa(t_dl_lst *stack_a, int write_sa)
{
	if (!stack_a || ft_dl_lst_size(stack_a) <= 1)
		return ;
	ft_swap_two_last_elements(stack_a);
	if (write_sa)
		ft_putendl("sa");
}
