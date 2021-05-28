/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_min_in_top_half.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:36:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/28 15:00:05 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_min_in_top_half(t_dl_lst *dl_lst)
** !last element of the stack is the top element!
** This function returns:
** 1 if the minimum is closer to the top of the stack (we use ra/rb/rr)
** 0 if the minimum is closer to the bottom of the stack (we use rra/rrb/rrr)
*/

int	ft_dl_lst_min_in_top_half(t_dl_lst *dl_lst)
{
	int			dl_lst_size;
	int			current_pos;
	int			min;
	t_dl_lst	*current_dl_lst;

	if (!dl_lst)
		return (-1);
	dl_lst_size = ft_dl_lst_size(dl_lst);
	min = ft_dl_lst_lowest_content(dl_lst);
	current_pos = 0;
	current_dl_lst = ft_dl_lst_first(dl_lst);
	while (current_dl_lst->content != min)
	{
		current_pos++;
		current_dl_lst = current_dl_lst->next;
	}
	if (current_pos > dl_lst_size / 2)
		return (1);
	return (0);
}
