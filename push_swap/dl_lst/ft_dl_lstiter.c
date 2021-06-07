/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:39:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 14:59:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** FT_DL_LSTITER
** It will apply function f to all of the elements
** before and after the *lst element
*/

void	ft_dl_lstiter(t_dl_lst *lst, void (*f)(int))
{
	t_dl_lst	*temp;

	if (!lst || !f)
		return ;
	temp = ft_dl_lst_first(lst);
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
