/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:50:15 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/08 16:36:59 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_pa(t_dl_lst **stack_b, t_dl_lst **stack_a)
** This function is responsible for both pa instruction
** pa:	push a - take the element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void	ft_pa(t_dl_lst **stack_b, t_dl_lst **stack_a)
{
	t_dl_lst	*first;
	t_dl_lst	*second;
	t_dl_lst	*temp;

	if (!stack_b || !stack_a || !*stack_b)
		return ;
	first = *stack_b;
	second = first->next;
	if (!*stack_a)
		*stack_a = ft_dl_lst_new_exit(first->content);
	else
	{
		temp = ft_dl_lst_new_exit(first->content);
		(*stack_a)->previous = temp;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	*stack_b = second;
	free(first);
	first = 0;
	ft_putendl("pa");
}
