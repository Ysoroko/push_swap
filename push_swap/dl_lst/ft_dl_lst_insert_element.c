/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_insert_element.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:48:35 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 17:16:40 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** FT_DL_LST_INSERT_ELEMENT
** This function inserts the element "to_insert" in the middle of the dll
** (double linked list) and links it to the previous and next element
*/

void	ft_dl_lst_insert_element(t_dl_lst *new, t_dl_lst *after, t_dl_lst *bef)
{
	if (!new)
	{
		after->next = new;
		bef->previous = new;
		return ;
	}
	if (after)
	{
		after->next = new;
		new->previous = after;
	}
	if (bef)
	{
		bef->previous = new;
		new->next = bef;
	}
}
