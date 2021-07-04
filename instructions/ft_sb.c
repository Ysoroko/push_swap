/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:29:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/04 14:32:32 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_sb(t_dl_lst **stack_a)
** This function is responsible for the following operations:
** sb:	switches last two elements of the stack_b
** If the stack is empty or counts less than 2 elements, do nothing.
*/

int	ft_sb(t_dl_lst **stack_b, int write_sb)
{
	t_dl_lst	*first;
	t_dl_lst	*second;
	t_dl_lst	*third;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	first = *stack_b;
	second = first->next;
	third = second->next;
	*stack_b = second;
	second->next = first;
	second->previous = 0;
	first->previous = second;
	first->next = third;
	if (third)
		third->previous = first;
	if (write_sb)
		ft_putendl("sb");
	return (1);
}
