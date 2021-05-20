/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:33:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 16:37:22 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_dl_lst_swap(t_dl_lst *element_1, t_dl_lst *element_2)
** This function will swap the place of 2 elements of t_dl_lst
*/

void	ft_dl_lst_swap(t_dl_lst *element_1, t_dl_lst *element_2)
{
	if (!element_1 || !element_2)
		return ;
	if (element_1->previous)
		(element_1->previous)->next = element_2;
	if (element_2->next)
		(element_2->next)->previous = element_1;
}
