/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:43:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 15:12:58 by ysoroko          ###   ########.fr       */
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

int	ft_put_next_on_the_top_of_a(t_dl_lst **a, t_dl_lst **b, int *p, int l)
{
	int	next_elem_from_top;
	int	next_elem_bottom;
	int	n_ops_top;
	int	n_ops_bottom;
	int	number_of_ops_used;

	number_of_ops_used = 0;
	next_elem_from_top = ft_first_elem_from_next_part_top(*a, *b, p, l);
	next_elem_bottom = ft_first_elem_from_next_prt_bottom(*a, *b, p, l);
	n_ops_top = ft_number_of_moves_from_the_top(*a, next_elem_from_top);
	n_ops_bottom = ft_number_of_moves_from_the_bottom(*a, next_elem_bottom);
	if (n_ops_top <= n_ops_bottom)
	{
		while (*a && (*a)->content != next_elem_from_top)
			number_of_ops_used += ft_ra(a, 1);
	}
	else
	{
		while (*a && (*a)->content != next_elem_bottom)
			number_of_ops_used += ft_rra(a, 1);
	}
	return (number_of_ops_used);
}

/*
** int	ft_rotate_b_to_accept_new_element(t_dl_lst **stack_b, int elem)
** This function will rotate stack_b appropriately to accept the new element
** from the top of the stack_a. 
*/

int	ft_rotate_b_to_accept_new_elem(t_dl_lst **stack_b, int elem)
{
	int	n_ops_top;
	int	next;
	int	n_ops_bottom;
	int	n_ops;

	if (elem > ft_dl_lst_max(*stack_b) || elem < ft_dl_lst_min(*stack_b))
		next = ft_dl_lst_max(*stack_b);
	else
		next = ft_dl_lst_next_content(*stack_b, elem);
	n_ops_bottom = ft_dl_lst_n_rrot_to_reach_elem(*stack_b, next);
	n_ops_top = ft_dl_lst_n_rot_to_reach_elem(*stack_b, next);
	n_ops = 0;
	if (n_ops_top < n_ops_bottom)
	{
		while ((*stack_b)->content != next)
			n_ops += ft_rb(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->content != next)
			n_ops += ft_rrb(stack_b, 1);
	}
	return (n_ops);
}

/*
** int	ft_send_top_elem_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b)
** This function will send the top element of stack_a to stack_b.
** It will find the right spot to put it in b.
** Returns the number of operations performed
*/

int	ft_send_top_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	int	top_content;
	int	min_in_b;
	int	max_in_b;
	int	n_ops;

	top_content = (*stack_a)->content;
	n_ops = 0;
	if (*stack_b)
	{
		n_ops += ft_rotate_b_to_accept_new_elem(stack_b, top_content);
		ft_pb(stack_a, stack_b, 1);
		return (n_ops + 1);
	}
	ft_pb(stack_a, stack_b, 1);
	return (1);
}

/*
** void	ft_send_next_part_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b,
**								int *sorted_a, int n_elems)
** This function is responsible for sending the entire next "part" of stack_a
** to stack_b
*/

int	ft_snd_next_part_to_b(t_dl_lst **a, t_dl_lst **b, int *part, int len)
{
	int	parts_length;
	int	current_n_elemts;
	int	n_ops;

	n_ops = 0;
	parts_length = len;
	while (*a && parts_length)
	{
		n_ops += ft_put_next_on_the_top_of_a(a, b, part, len);
		n_ops += ft_send_top_to_b(a, b);
		parts_length--;
	}
	return (n_ops);
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

void	ft_general_algo(t_dl_lst **s_a, int *sort_a, int l)
{
	t_dl_lst	*stack_b;
	int			n_ops;
	int			*next_p;
	int			current_part_offset;
	int			offset;

	ft_initialize_variables_for_algo(&n_ops, &stack_b, &current_part_offset);
	next_p = sort_a;
	offset = l / N_PARTS_GENERAL;
	while (*s_a && current_part_offset < l && !ft_stack_a_is_sorted(*s_a))
	{
		next_p = &(sort_a[current_part_offset]);
		n_ops += ft_snd_next_part_to_b(s_a, &stack_b, next_p, offset);
		if (ft_int_elem_is_in_next_part(sort_a[l - 1], next_p, offset))
			offset = ft_index_of_element_in_int_tab(sort_a[l], next_p, offset);
		current_part_offset += offset;
	}
	while (ft_dl_lst_last(stack_b)->content != sort_a[0])
		if (ft_number_of_moves_from_the_bottom(stack_b, sort_a[0])
			<= ft_number_of_moves_from_the_top(stack_b, sort_a[0]))
			n_ops += ft_rrb(&stack_b, 1);
	else
		n_ops += ft_rb(&stack_b, 1);
	while (stack_b)
		n_ops += ft_pa(&stack_b, s_a, 1);
}
