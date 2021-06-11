/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:17:44 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/11 15:22:28 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** static int	ft_find_min_value(t_dl_lst *stack_a, t_dl_lst **min_dl_lst)
** This function will find the minimum value in stack_a, return the value and
** set *min_dl_lst argument to be the address of t_dl_lst containing this min
** value
** Returns 0 if stack_a or min_dl_lst is NULL
*/

static int	ft_find_min_value(t_dl_lst *stack_a, t_dl_lst **min_dl_lst)
{
	int			min;
	t_dl_lst	*current;
	t_dl_lst	*min_member;

	if (!stack_a || !min_dl_lst)
		return (0);
	min = stack_a->content;
	min_member = stack_a;
	current = stack_a;
	while (current)
	{
		if (current->content < min)
		{
			min = current->content;
			min_member = current;
		}
		current = current->next;
	}
	*min_dl_lst = min_member;
	return (min);
}

static void	ft_update_min(t_dl_lst *stack_a, int *min_value, int *index_of_min)
{
	t_dl_lst	*min_dl_lst;

	*min_value = ft_find_min_value(stack_a, &min_dl_lst);
	*index_of_min = ft_dl_lst_current_index(stack_a, min_dl_lst);
}

static void	ft_send_min_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b, int *n_op)
{
	int			min_value;
	int			stack_a_size;
	int			index_of_min_dl_lst;
	t_dl_lst	*min_dl_lst;

	if (!stack_a || !stack_b || !n_op)
		return ;
	stack_a_size = ft_dl_lst_size(*stack_a);
	min_value = ft_find_min_value(*stack_a, &min_dl_lst);
	index_of_min_dl_lst = ft_dl_lst_current_index(*stack_a, min_dl_lst);
	if (index_of_min_dl_lst < stack_a_size / 2)
	{
		while ((*stack_a)->content != min_value && !ft_stack_a_is_sorted(*stack_a))
		{	
			ft_ra(stack_a, 1);
			(*n_op)++;
		}
	}
	else
	{
		while ((*stack_a)->content != min_value && !ft_stack_a_is_sorted(*stack_a))
		{
			ft_rra(stack_a, 1);
			(*n_op)++;
		}
	}
	ft_pb(stack_a, stack_b, 1);
	(*n_op)++;
}

/*
** void	ft_general_algo(t_dl_lst **stack_a)
** This is the main algo used when the number of elements in stack_a
** is too big for any other algo
*/

void	ft_general_algo(t_dl_lst **stack_a)
{
	t_dl_lst	*stack_b;
	int			number_of_operations;
	int			initial_stack_a_size;

	number_of_operations = 0;
	initial_stack_a_size = ft_dl_lst_size(*stack_a);
	stack_b = 0;
	while (*stack_a && !ft_stack_a_is_sorted(*stack_a))
	{
		if (ft_top_two_elems_to_swap(*stack_a))
		{
			ft_sa(stack_a, 1);
			number_of_operations++;
		}
		ft_send_min_to_b(stack_a, &stack_b, &number_of_operations);
	}
	while (stack_b)
	{
		ft_pa(&stack_b, stack_a, 1);
		number_of_operations++;
	}
	ft_print_stacks(*stack_a, stack_b);
	printf("Number of operations: [%d]\n", number_of_operations);
}

/*
** Limits:
** 3 elements: 2 or 3 operations max
** 5 elements: 12 max (8 = very good)
** 100 elements: <700 = 5/5	<1500 = 1/5
** 500 elements: <5500 = 5/5	<11500 = 1/5
*/