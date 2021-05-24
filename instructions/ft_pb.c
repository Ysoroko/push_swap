/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:01:12 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 09:53:01 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_pb(t_dl_lst *stack_a, t_dl_lst *stack_b)
** This function is responsible for both pa and pb instructions
** pb:	push b - take the element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void	ft_pb(t_dl_lst *stack_stack_a, t_dl_lst **stack_b)
{
	t_dl_lst	*element_to_move;

	if (!stack_stack_a || !stack_b)
		return ;
	element_to_move = ft_dl_lst_last(stack_stack_a);
	if (*stack_b)
		ft_dl_lst_add_back(*stack_b, element_to_move);
	else
		*stack_b = ft_dl_lst_new_exit(element_to_move->content);
	ft_dl_lst_remove_last(stack_stack_a);
	ft_putendl("pb");
}
