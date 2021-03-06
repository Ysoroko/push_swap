/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_is_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:51:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 15:41:56 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_stack_a_is_sorted(t_dl_lst *stack_a)
** This function will check if the dl_lst provided in argument is sorted
** in order low->high (low being at the bottom of the stack!)
** Will return 1 if it is sorted low->high 
** Will return 0 if it is not sorted this way
** Will return -1 if stack_a is a NULL pointer
*/

int	ft_stack_a_is_sorted(t_dl_lst *stack_a)
{
	int			current_value;
	int			previous_value;
	t_dl_lst	*current_element;

	if (!stack_a)
		return (-1);
	current_element = stack_a;
	previous_value = current_element->content;
	current_element = current_element->next;
	while (current_element)
	{
		current_value = current_element->content;
		if (current_value < previous_value)
			return (0);
		previous_value = current_value;
		current_element = current_element->next;
	}
	return (1);
}
