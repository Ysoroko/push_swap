/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_n_rrot_to_reach_elem.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:16:40 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/02 12:21:19 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_n_rot_to_reach_elem(t_dl_lst *dl_lst, int elem)
** This function will calculate the number of rotations (rra/rrb, reversed)
** required to reach the elem argument in the dl_lst.
** Returns -1 in case of error, the number of rev rotations required otherwise.
*/

int	ft_dl_lst_n_rrot_to_reach_elem(t_dl_lst *dl_lst, int elem)
{
	t_dl_lst	*current;
	int			n_ops;

	if (!dl_lst)
		return (-1);
	n_ops = 1;
	current = ft_dl_lst_last(dl_lst);
	while (current && current->content != elem)
	{
		current = current->previous;
		n_ops++;
	}
	if (current->content != elem)
		return (-1);
	return (n_ops);
}
