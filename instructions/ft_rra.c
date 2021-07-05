/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:58:14 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/05 12:04:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rra(t_dl_lst *stack_to_rotate)
** rra:	Shift down all elements of the stack a by 1.
** The last element becomes the first one.
*/

int	ft_rra(t_dl_lst **stack_a, int write_rra)
{
	t_dl_lst	*first;
	t_dl_lst	*last;
	t_dl_lst	*before_last;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return (0);
	first = *stack_a;
	last = ft_dl_lst_last(*stack_a);
	before_last = last->previous;
	last->next = first;
	last->previous = 0;
	first->previous = last;
	before_last->next = 0;
	*stack_a = last;
	if (write_rra)
		ft_putendl("rra");
	return (1);
}
