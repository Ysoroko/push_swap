/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:58:14 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 09:59:00 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_rra(t_dl_lst *stack_to_rotate)
** rra:	Shift down all elements of the stack a by 1.
**			The last element becomes the first one.
*/

void	ft_rra(t_dl_lst *stack_a, int write_rra)
{
	t_dl_lst	*last;

	last = ft_dl_lst_last(stack_a);
	ft_dl_lst_add_front(stack_a, last);
	ft_dl_lst_remove_last(stack_a);
	ft_putendl("rra");
}