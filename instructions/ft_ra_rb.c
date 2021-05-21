/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:09:29 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 14:33:46 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_ra_rb(t_dl_lst *stack_to_rotate)
** ra/rb:	Shift up all elements of the stack by 1.
**			The first element becomes the last one.
*/

void	ft_ra_rb(t_dl_lst *stack_to_rotate)
{
	t_dl_lst	*first;

	first = ft_dl_lst_first(stack_to_rotate);
	ft_dl_lst_add_back(stack_to_rotate, first);
	ft_dl_lst_remove_first(stack_to_rotate);
}
