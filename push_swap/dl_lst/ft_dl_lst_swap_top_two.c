/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_swap_top_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:40:26 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/01 16:19:58 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_dl_lst_swap_top_two(t_dl_lst **dl_lst)
** This function will swap the top 2 elements of t_dl_lst
*/

void	ft_dl_lst_swap_top_two(t_dl_lst **dl_lst)
{
	t_dl_lst	*top;
	t_dl_lst	*second;
	t_dl_lst	*second_previous;

	top = ft_dl_lst_last(*dl_lst);
	second = top->previous;
	second_previous = second->previous;
	second->next = 0;
	second->previous = top;
	top->next = second;
	top->previous = second_previous;
}
