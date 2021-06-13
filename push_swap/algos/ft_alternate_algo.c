/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alternate_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:26:57 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/13 15:23:32 by ysoroko          ###   ########.fr       */
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

static void	ft_push_half_of_a_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b, int *n_ops)
{
	int	initial_a_size;

	initial_a_size = ft_dl_lst_size(*stack_a);
	while (ft_dl_lst_size(*stack_a) >= initial_a_size / 2 && !ft_stack_a_is_sorted(*stack_a))
	{
		ft_pb(stack_a, stack_b, 1);
		(*n_ops)++;
	}
}

static void	ft_sent_min_to_stack_b(t_dl_lst **stack_a, t_dl_lst **stack_b, int *n)
{
	int			min_value;
	t_dl_lst	*min_dl_lst;
	int			initial_stack_size;
	int			index_of_min_dl_lst;

	min_value = ft_find_min_value(*stack_a, &min_dl_lst);
	initial_stack_size = ft_dl_lst_size(*stack_a);
	index_of_min_dl_lst = ft_dl_lst_current_index(*stack_a, min_dl_lst) - 1;
	if (index_of_min_dl_lst > initial_stack_size / 2)
	{
		while (!ft_stack_a_is_sorted(*stack_a) && (*stack_a)->content != min_value)
		{
			ft_ra(stack_a, 1);
			(*n)++;
		}
	}
	else
	{
		while (!ft_stack_a_is_sorted(*stack_a) && (*stack_a)->content != min_value)
		{
			ft_rra(stack_a, 1);
			(*n)++;
		}
	}
	ft_pb(stack_a, stack_b, 1);
}

static void	ft_sent_min_to_stack_a(t_dl_lst **stack_a, t_dl_lst **stack_b, int *n)
{
	int			min_value;
	t_dl_lst	*min_dl_lst;
	int			initial_stack_size;
	int			index_of_min_dl_lst;

	min_value = ft_find_min_value(*stack_b, &min_dl_lst);
	initial_stack_size = ft_dl_lst_size(*stack_b);
	index_of_min_dl_lst = ft_dl_lst_current_index(*stack_b, min_dl_lst) - 1;
	if (index_of_min_dl_lst > initial_stack_size / 2)
	{
		while (!ft_stack_a_is_sorted(*stack_b) && (*stack_b)->content != min_value)
		{
			ft_rb(stack_b, 1);
			(*n)++;
		}
	}
	else
	{
		while (!ft_stack_a_is_sorted(*stack_b) && (*stack_b)->content != min_value)
		{
			ft_rrb(stack_b, 1);
			(*n)++;
		}
	}
	ft_pa(stack_b, stack_a, 1);
}

static void	ft_sort_stack_b(t_dl_lst **stack_b, t_dl_lst **stack_a, int *n_ops)
{
	int			min_value;
	t_dl_lst	*min_dl_lst;
	int			n_elems_sent_to_a;
	int			initial_stack_a_size;
	int			index_of_min_dl_lst;

	n_elems_sent_to_a = 0;
	min_value = ft_find_min_value(*stack_b, &min_dl_lst);
	initial_stack_a_size = ft_dl_lst_size(*stack_b);
	index_of_min_dl_lst = ft_dl_lst_current_index(*stack_b, min_dl_lst);
	if (index_of_min_dl_lst < initial_stack_a_size / 2)
	while (!ft_stack_a_is_sorted(*stack_b))
	{
		if (ft_top_two_elems_to_swap(*stack_b))
		{
			ft_sb(stack_b, 1);
			(*n_ops)++;
		}
		ft_sent_min_to_stack_a(stack_a, stack_b, n_ops);
		n_elems_sent_to_a++;
	}
	while (n_elems_sent_to_a)
	{
		ft_pb(stack_a, stack_b, 1);
		n_elems_sent_to_a--;
	}
}

static void	ft_sort_stack_a(t_dl_lst **stack_a, t_dl_lst **stack_b, int *n_ops)
{
	t_dl_lst	*min_dl_lst;
	int			n_elems_sent_to_b;
	int			initial_stack_a_size;
	int			index_of_min_dl_lst;

	n_elems_sent_to_b = 0;
	min_dl_lst = 0;
	initial_stack_a_size = ft_dl_lst_size(*stack_a);
	index_of_min_dl_lst = ft_dl_lst_current_index(*stack_a, min_dl_lst);
	if (index_of_min_dl_lst < initial_stack_a_size / 2)
	while (!ft_stack_a_is_sorted(*stack_a))
	{
		if (ft_top_two_elems_to_swap(*stack_a))
		{
			ft_sa(stack_a, 1);
			(*n_ops)++;
		}
		ft_sent_min_to_stack_b(stack_a, stack_b, n_ops);
		n_elems_sent_to_b++;
	}
	while (n_elems_sent_to_b)
	{
		ft_pa(stack_b, stack_a, 1);
		n_elems_sent_to_b--;
	}
}

/*
** general logic: divide the arguments into 2 stacks, sort each of them, then merge
*/

void	ft_alternate_algo(t_dl_lst **stack_a)
{
	int			n_ops;
	t_dl_lst	*stack_b;

	n_ops = 0;
	stack_b = 0;
	ft_push_half_of_a_to_b(stack_a, &stack_b, &n_ops);
	ft_sort_stack_a(stack_a, &stack_b, &n_ops);
	ft_sort_stack_b(&stack_b, stack_a, &n_ops);
	ft_print_stacks(*stack_a, stack_b);
	printf("Number of operations: [%d]\n",n_ops);
}