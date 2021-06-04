/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_remove_first.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:12:47 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/04 12:14:27 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_dl_lst_remove_first(t_dl_lst **dl_lst)
{
	t_dl_lst	*first;

	if (!dl_lst || !*dl_lst)
		return ;
	first = ft_dl_lst_first(*dl_lst);
	if (!first->next)
	{
		free(first);
		*dl_lst = 0;
		return ;
	}
	free(first);
	first = 0;
}
