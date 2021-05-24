/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_is_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:11:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 10:38:35 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_is_sorted(t_dl_lst *lst, int ascending_order)
** Same as ft_int_tab_is_sorted, but this function will verify the dl_lst
** in the specified order.
** If ascending_order argument is different than 0, every t_dl_lst member's 
** int content needs to be lower than the next one.
** Otherwise if ascending_order argument is equal to 0, every t_dl_lst member's 
** int content needs to be higher than the next one.
** Returns 1 if the dl_lst is sorted in the specified order, 0 otherwise
*/

int	ft_dl_lst_is_sorted(t_dl_lst *lst, int ascending_order)
{
	t_dl_lst	*current;
	int			current_value;
	int			next_value;

	if (!lst)
		return (0);
	current = ft_dl_lst_first(lst);
	while (current->next)
	{
		current_value = current->content;
		next_value = current->next->content;
		if (ascending_order)
		{
			if (current_value > next_value)
				return (0);
		}
		else
		{
			if (current_value < next_value)
				return (0);
		}
		current = current->next;
	}
	return (1);
}
