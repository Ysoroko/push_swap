/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:00:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 12:24:29 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_sa(t_dl_lst **stack_a)
** This function is responsible for the following operations:
** sa:	switches last two elements of the stack_a
** If the stack is empty or counts less than 2 elements, do nothing.
*/

void	ft_sa(t_dl_lst **stack_a, int write_sa)
{
	if (!stack_a || !*stack_a || ft_dl_lst_size(*stack_a) <= 1)
		return ;
	ft_dl_lst_swap_top_two(stack_a);
	*stack_a = ft_dl_lst_first(stack_a);
	if (write_sa)
		ft_putendl("sa");
}
