/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_lowest_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:06:56 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/28 14:14:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_lowest_content(t_dl_lst *dl_lst)
** This function will find the minimal content value in the entire dl_lst
** and return it. Returns 0 if the dl_lst argument is NULL.
*/

int	ft_dl_lst_lowest_content(t_dl_lst *dl_lst)
{
	int			min;
	t_dl_lst	*current_dl_lst;

	if (!dl_lst)
		return (0);
	current_dl_lst = ft_dl_lst_first(dl_lst);
	min = current_dl_lst->content;
	current_dl_lst = current_dl_lst->next;
	while (current_dl_lst)
	{
		if (current_dl_lst->content < min)
			min = current_dl_lst->content;
	}
	return (min);
}