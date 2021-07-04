/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_or_less_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:43:27 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/04 14:36:51 by ysoroko          ###   ########.fr       */
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

/*
** void	ft_send_min_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b, int *n_op)
** This function will find the minimum value in stack_a, perform ra or rra
** based on its place and then push it to stack_b
*/

static void	ft_send_min_to_b(t_dl_lst **st_a, t_dl_lst **stack_b, int *n_op)
{
	int			min_value;
	int			stack_a_size;
	int			middle;
	int			index_of_min_dl_lst;
	t_dl_lst	*min_dl_lst;

	if (!st_a || !stack_b || !n_op)
		return ;
	stack_a_size = ft_dl_lst_size(*st_a);
	if (stack_a_size % 2)
		middle = (stack_a_size / 2) + 1;
	else
		middle = (stack_a_size / 2);
	min_dl_lst = 0;
	min_value = ft_find_min_value(*st_a, &min_dl_lst);
	index_of_min_dl_lst = ft_dl_lst_current_index(*st_a, min_dl_lst) - 1;
	if (index_of_min_dl_lst < middle)
		while ((*st_a)->content != min_value && !ft_stack_a_is_sorted(*st_a))
			(*n_op) += ft_ra(st_a, 1);
	else
		while ((*st_a)->content != min_value && !ft_stack_a_is_sorted(*st_a))
			(*n_op) += ft_rra(st_a, 1);
	if (!ft_stack_a_is_sorted(*st_a))
		(*n_op) += ft_pb(st_a, stack_b, 1);
}

/*
** void	ft_five_or_less_algo(t_dl_lst **stack_a)
** This is algo used when stack_a has 5 or less elements
** It will sort it in max 10 operations (12 is allowed max)
** The logic is to find the minimum value in stack_a,
** perform ra/rra depending on its place to place it on top
** and then push it to stack_b
** When remaining stack_a is sorted, we push everything
** from stack_b to stack_a using "pa" and obtain a sorted stack_a
*/

void	ft_five_or_less_algo(t_dl_lst **stack_a)
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
}
