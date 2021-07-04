/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:09:29 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/04 14:30:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_ra_rb(t_dl_lst *stack_to_rotate)
** ra/rb:	Shift up all elements of the stack by 1.
**			The first element becomes the last one.
*/

int	ft_rb(t_dl_lst **stack_b, int write_rb)
{
	t_dl_lst	*last;
	t_dl_lst	*first;
	t_dl_lst	*second;

	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return (0);
	last = ft_dl_lst_last(*stack_b);
	first = *stack_b;
	second = first->next;
	last->next = first;
	first->next = 0;
	first->previous = last;
	second->previous = 0;
	*stack_b = second;
	if (write_rb)
		ft_putendl("rb");
	return (1);
}
