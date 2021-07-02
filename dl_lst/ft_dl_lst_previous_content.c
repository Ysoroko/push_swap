/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_previous_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:59:12 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/02 12:00:48 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_previous_content(t_dl_lst *dl_lst, int new_content)
** This function will find which content in dl_lst
** should be previous before new_content
** Returns the content's int value. If there is no previous element
** or dl_lst is 0, returns the value of new_content
*/

int	ft_dl_lst_previous_content(t_dl_lst *dl_lst, int new_content)
{
	t_dl_lst	*current;
	int			previous;
	int			current_content;

	if (!dl_lst)
		return (new_content);
	current = dl_lst;
	previous = new_content;
	while (current)
	{
		current_content = current->content;
		if (current_content < new_content && current_content > previous)
			previous = current_content;
		current = current->next;
	}
	return (previous);
}
