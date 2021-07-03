/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_next_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:53:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/03 16:22:29 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_next_content(t_dl_lst *dl_lst, int new_content)
** This function will find which content in dl_lst
** should be next after new_content
** Returns the content's int value. If there is no next element or dl_lst is 0,
** returns the value of new_content
*/

int	ft_dl_lst_next_content(t_dl_lst *dl_lst, int new_content)
{
	t_dl_lst	*current;
	int			next;
	int			current_content;

	if (!dl_lst)
		return (new_content);
	current = dl_lst;
	next = dl_lst->content;
	while (current)
	{
		current_content = current->content;
		if (current != dl_lst)
		{
			if (current_content < next &&
				current->previous->content > new_content)
				next = current_content;
		}
		else
		{
			if (current_content < new_content &&
				ft_dl_lst_last(dl_lst)->content > current_content)
				next = ft_dl_lst_last(dl_lst)->content;
		}
		current = current->next;
	}
	return (next);
}
