/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_of_moves_from_the_bottom.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:38:09 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/01 12:40:24 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_number_of_moves_from_the_bottom(t_dl_lst *stack_a, int until_elem)
** This function calculates how many moves are necessary to reach "until_elem"
** from the bottom of the stack_a (how many "rra" we need to perform).
** The counter of moves starts at 1 because we need to perform one "rra"
** to reach the bottom of stack_a
*/

int	ft_number_of_moves_from_the_bottom(t_dl_lst *stack_a, int until_elem)
{
	int			number_of_moves;
	t_dl_lst	*current;

	number_of_moves = 1;
	current = ft_dl_lst_last(stack_a);
	while (current && current->content != until_elem)
	{
		current = current->previous;
		number_of_moves++;
	}
	return (number_of_moves);
}
