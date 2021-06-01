/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_is_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:51:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/01 14:04:49 by ysoroko          ###   ########.fr       */
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
	{
		printf("no stack_a\n");
		return (-1);
	}
	printf("stack_a\n");
	current_element = ft_dl_lst_last(stack_a);
	printf("current_element: [%d]\n", current_element->content);
	previous_value = current_element->content;
	current_element = current_element->previous;
	printf("before while in sorted?\n");
	while (current_element)
	{
		printf("sorted???\n");
		current_value = current_element->content;
		if (current_value < previous_value)
		{
			printf("not sorted\n");
			return (0);
		}
		previous_value = current_value;
		current_element = current_element->previous;
		printf("here k\n");
	}
	printf("here ok\n");
	return (1);
}
