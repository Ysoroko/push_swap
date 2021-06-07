/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_delone_relink.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:27:04 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 14:57:52 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** FT_DL_LSTDELONE_RELINK
** This function will remove one specific t_dl_lst element and its content
** ! relinks the previous and next elements
*/

void	ft_dl_lstdelone_relink(t_dl_lst *to_delete)
{
	t_dl_lst	*prev;
	t_dl_lst	*next;

	if (!to_delete)
		return ;
	prev = to_delete->previous;
	next = to_delete->next;
	free(to_delete);
	if (prev)
		prev->next = next;
	if (next)
		next->previous = prev;
}
