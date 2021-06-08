/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:01:12 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/08 13:40:17 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_pb(t_dl_lst *stack_a, t_dl_lst *stack_b)
** This function is responsible for both pa and pb instructions
** pb:	push b - take the element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void	ft_pb(t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	t_dl_lst	*first;
	t_dl_lst	*second;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	first = *stack_a;
	second = first->next;
	if (!*stack_b)
	{
		*stack_b = ft_dl_lst_new_exit(first->content);
		printf("stack b when no b: [%d]\n", (*stack_b)->content);
	}
	else
	{
		ft_dl_lst_add_front(stack_b, ft_dl_lst_new_exit(first->content));
		printf("stack b when b: [%d]\n", (*stack_b)->content);
	}
	*stack_a = second;
	free(first);
	first = 0;
	printf("stack b: [%d]\n", (*stack_b)->content);
	ft_putendl("pb");
}
