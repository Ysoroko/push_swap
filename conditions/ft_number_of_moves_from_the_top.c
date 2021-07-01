/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_of_moves_from_the_top.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:33:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/01 12:37:16 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_number_of_moves_from_the_top(t_dl_lst *stack_a, int until_elem)
** This function calculates how many moves are necessary to reach "until_elem"
** from the top of the stack_a (how many "ra" we need to perform)
*/

int	ft_number_of_moves_from_the_top(t_dl_lst *stack_a, int until_elem)
{
	int			number_of_moves;
	t_dl_lst	*current;

	number_of_moves = 0;
	current = stack_a;
	while (current && current->content != until_elem)
	{
		current = current->next;
		number_of_moves++;
	}
	return (number_of_moves);
}
