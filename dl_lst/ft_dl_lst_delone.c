/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_delone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:23:26 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/19 10:52:37 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** FT_DL_LSTDELONE
** This function will remove one specific t_dl_lst element and its content
** ! doesn't relink the previous and next elements
*/

void	ft_dl_lstdelone(t_dl_lst *to_delete, void (*del)(void*))
{
	if (!to_delete || !del)
		return ;
	del(to_delete->content);
	free(to_delete);
	to_delete = 0;
}
