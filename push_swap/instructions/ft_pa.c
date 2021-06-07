/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:50:15 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 13:55:36 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_pa(t_dl_lst *stack_a, t_dl_lst *stack_b)
** This function is responsible for both pa instruction
** pa:	push a - take the element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void	ft_pa(t_dl_lst **stack_b, t_dl_lst **stack_a)
{
	t_dl_lst	*element_to_move;
	t_dl_lst	*new_element;

	if (!stack_b || !*stack_b || !stack_a)
		return ;
	element_to_move = ft_dl_lst_last(*stack_b);
	new_element = ft_dl_lst_new_exit(element_to_move->content);
	if (*stack_a)
		ft_dl_lst_add_back(stack_a, new_element);
	else
		*stack_a = new_element;
	ft_dl_lst_remove_last(stack_b);
	ft_putendl("pa");
}
