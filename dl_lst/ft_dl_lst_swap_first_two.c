/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_swap_first_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:40:26 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/01 14:58:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_dl_lst_swap(t_dl_lst *element_1, t_dl_lst *element_2)
** This function will swap the place of 2 elements of t_dl_lst
*/

void	ft_dl_lst_swap_first_two(t_dl_lst **dl_lst)
{
	t_dl_lst	*first;
	t_dl_lst	*second;
	t_dl_lst	*second_next;

	first = ft_dl_lst_first(*dl_lst);
	second = first->next;
	second_next = second->next;
	*dl_lst = second;
	second->next = first;
	first->next = second_next;
	first->previous = second;
}
