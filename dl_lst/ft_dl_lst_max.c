/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:33:32 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/01 16:34:02 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	f_dl_lst_max(t_dl_lst *dl_lst)
** This function will find the maximum value in dl_lst and returns it.
** Returns 0 if dl_lst is a NULL pointer
*/

int	f_dl_lst_max(t_dl_lst *dl_lst)
{
	int			max;
	t_dl_lst	*current;

	if (!dl_lst)
		return (0);
	current = dl_lst;
	max = dl_lst->content;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}
