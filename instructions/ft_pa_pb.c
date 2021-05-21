/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:01:12 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 14:33:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_pa_pb(t_dl_lst *stack_a, t_dl_lst *stack_b)
** This function is responsible for both pa and pb instructions
** pa:	push a - take the element at the top of b and put it at the top of a.
** Do nothing if b is empty.
** pb:	push b - take the element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void	ft_pa_pb(t_dl_lst *stack_to_move_from, t_dl_lst **stack_to_move_to)
{
	t_dl_lst	*element_to_move;

	if (!stack_to_move_from || !stack_to_move_to)
		return ;
	element_to_move = ft_dl_lst_last(stack_to_move_from);
	if (*stack_to_move_to)
		ft_dl_lst_add_back(*stack_to_move_to, element_to_move);
	else
		*stack_to_move_to = ft_dl_lst_new_exit(element_to_move->content);
	ft_dl_lst_remove_last(stack_to_move_from);
}
