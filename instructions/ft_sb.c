/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:29:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 12:24:52 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_sb(t_dl_lst **stack_a)
** This function is responsible for the following operations:
** sb:	switches last two elements of the stack_b
** If the stack is empty or counts less than 2 elements, do nothing.
*/

void	ft_sb(t_dl_lst **stack_b, int write_sb)
{
	if (!stack_b || !*stack_b || ft_dl_lst_size(*stack_b) <= 1)
		return ;
	ft_dl_lst_swap_top_two(stack_b);
	*stack_b = ft_dl_lst_first(stack_b);
	if (write_sb)
		ft_putendl("sb");
}
