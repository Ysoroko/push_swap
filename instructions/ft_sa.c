/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:00:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/05 14:56:04 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_sa(t_dl_lst **stack_a)
** This function is responsible for the following operations:
** sa:	switches last two elements of the stack_a
** If the stack is empty or counts less than 2 elements, do nothing.
** null <- 1 <-> 2 <-> 3
** null <- 2 <-> 1	 3
** null <- 2 <-> 1 <-> 3
*/

int	ft_sa(t_dl_lst **stack_a, int write_sa)
{
	t_dl_lst	*first;
	t_dl_lst	*second;
	t_dl_lst	*third;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	first = *stack_a;
	second = first->next;
	third = second->next;
	*stack_a = second;
	second->next = first;
	second->previous = 0;
	first->previous = second;
	first->next = third;
	if (third)
		third->previous = first;
	if (write_sa)
		ft_putendl("sa", STDOUT);
	return (1);
}
