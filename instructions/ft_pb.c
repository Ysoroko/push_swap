/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:01:12 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 12:16:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_pb(t_dl_lst *stack_a, t_dl_lst *stack_b)
** This function is responsible for both pa and pb instructions
** pb:	push b - take the element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void	ft_rb(t_dl_lst **stack_b, int write_rb)
{
	t_dl_lst	*first;

	if (!stack_b)
		return ;
	first = ft_dl_lst_first(*stack_b);
	ft_dl_lst_add_back(stack_b, first);
	ft_dl_lst_remove_first(stack_b);
	*stack_b = ft_dl_lst_first(*stack_b);
	if (write_rb)
		ft_putendl("rb");
}
