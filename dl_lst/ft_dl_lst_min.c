/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:30:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/02 12:09:52 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_min(t_dl_lst *dl_lst)
** This function will find the minimum value in dl_lst and returns it.
** Returns 0 if dl_lst is a NULL pointer
*/

int	ft_dl_lst_min(t_dl_lst *dl_lst)
{
	int			min;
	t_dl_lst	*current;

	if (!dl_lst)
		return (0);
	current = dl_lst;
	min = dl_lst->content;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}
