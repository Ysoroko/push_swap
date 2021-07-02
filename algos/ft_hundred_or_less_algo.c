/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred_or_less_algo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:43:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/01 17:02:11 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_put_next_elem_on_the_top_of_a(t_dl_lst **stack_a, int *part, int ln)
** This function will look for the closest element from the next part of stack,
** both from the top and the bottom, will compare the number of operations
** needed to reach it from the top/bottom, then choose the "closest"
** element and apply the needed rotations until the element is at the top of
** the stack
** It returns the number of operations used
*/

int	ft_put_next_elem_on_the_top_of_a(t_dl_lst **stack_a, int *part, int ln)
{
	int	next_elem_from_top;
	int	next_elem_bottom;
	int	n_ops_top;
	int	n_ops_bottom;
	int	number_of_ops_used;

	number_of_ops_used = 0;
	next_elem_from_top = ft_first_elem_from_next_part_top(*stack_a, part, ln);
	next_elem_bottom = ft_first_elem_from_next_part_bottom(*stack_a, part, ln);
	n_ops_top = ft_first_elem_from_next_part_top(*stack_a, part, ln);
	n_ops_bottom = ft_first_elem_from_next_part_bottom(*stack_a, part, ln);
	if (n_ops_top >= n_ops_bottom)
	{
		while (*stack_a && (*stack_a)->content != next_elem_from_top)
		{
			ft_ra(stack_a, 1);
			number_of_ops_used++;
		}
	}
	else
	{
		while (*stack_a && (*stack_a)->content != next_elem_bottom)
		{
			ft_rra(stack_a, 1);
			number_of_ops_used++;
		}
	}
	return (number_of_ops_used);
}

int	ft_rotate_b_to_accept_new_element(t_dl_lst **stack_b, int elem)
{
	int			n_ops_top;
	int			next;
	int			previous;
	int			n_ops_bottom;
	t_dl_lst	*current;

	n_ops_bottom = 0;
	n_ops_top = 0;
	if ((*stack_b)->content > elem && ft_dl_lst_last(*stack_b) < elem)
		return (0);
	while ()

}

/*
** int	ft_send_top_elem_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b)
** This function will send the top element of stack_a to stack_b.
** It will find the right spot to put it in b.
** Returns the number of operations performed
*/

int	ft_send_top_elem_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	int	top_content;
	int	min_in_b;
	int	max_in_b;
	int	n_operations;

	top_content = (*stack_a)->content;
	n_operations = 0;
	if (*stack_b)
	{
		min_in_b = ft_dl_lst_min(*stack_b);
		max_in_b = ft_dl_lst_max(*stack_b);
		if (top_content > max_in_b)
		{
			ft_pb(stack_a, stack_b, 1);
			ft_rrb(stack_b, 1);
			return (2);
		}
		else if (top_content < min_in_b)
		{
			ft_pb(stack_a, stack_b, 1);
			return (1);
		}
		else
		{
			while ()
		}
		
	}
}

/*
** void	ft_send_next_part_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b,
**								int *sorted_a, int n_elems)
** This function is responsible for sending the entire next "part" of stack_a
** to stack_b
*/

void	ft_send_next_part_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b,
								int *sorted_a, int n_elems)
{
	int	*next_part;
	int	parts_length;
	int	current_n_elemts;

	parts_length = n_elems / N_PARTS_UNDER_HUNDRED;
	next_part = sorted_a;
	



}

/*
** This algo will divide the sorted copy of stack_a in 5 parts.
** Every part containining numbers from smallest to bigger and same goes for
** every part itself (part 2 will contain numbers bigger than part 3)
** Example: Stack_a: {1 2 3 4 5}. Part 1: {1}. Part 2: {2}. Part 3: {3} etc.
** It will then look in the unsorted version of stack_a to see if a member
** of the next part is present closer to the top or to the bottom.
** Depending on its place in stack_a, we will rotate/reverse rotate the stack
** to put the element at the top.
** The next step is to push it to the top of stack_b, but before we do that we
** can optimize the algo further by checking if the number we're pushing to b
** is bigger/smaller than all the other numbers in b and place in in the right
** spot.
** We then push it to stack_b, repeat the previous steps until all numbers
** from 1st part are in stack_b, move on to the next part of elements and
** continue until there are no more parts in stack_a
*/

void	ft_hundred_or_less_algo(t_dl_lst **stack_a, int *sorted_a, int n_elems)
{
	t_dl_lst	*stack_b;
	int			number_of_operations;
	int			initial_stack_a_size;

	number_of_operations = 0;
	initial_stack_a_size = ft_dl_lst_size(*stack_a);
	stack_b = 0;
	while (*stack_a)
	{
		ft_send_next_part_to_b(stack_a, &stack_b, sorted_a, n_elems);
	}
	while (stack_b)
	{
		ft_pa(&stack_b, stack_a, 1);
		number_of_operations++;
	}
}
