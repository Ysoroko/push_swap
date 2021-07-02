/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred_or_less_algo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:43:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/02 15:13:22 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_print_next_part(int *part, int len)
{
	int i;

	i = -1;
	printf("len: [%d]\n", len);
	printf("Current part: ");
	while (++i < len)
		printf("%d ", part[i]);
	printf("\n");
}

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
	if (!ft_int_elem_is_in_next_part(next_elem_from_top, part, ln) || !ft_int_elem_is_in_next_part(next_elem_bottom, part, ln))
		return (0);
	n_ops_top = ft_first_elem_from_next_part_top(*stack_a, part, ln);
	n_ops_bottom = ft_first_elem_from_next_part_bottom(*stack_a, part, ln);
	if (n_ops_top >= n_ops_bottom)
	{
		while (*stack_a && (*stack_a)->content != next_elem_from_top)
		{
			ft_print_next_part(part, ln);
			ft_ra(stack_a, 1);
			ft_print_stacks(*stack_a, 0);
			number_of_ops_used++;
		}
	}
	else
	{
		while (*stack_a && (*stack_a)->content != next_elem_bottom)
		{
			ft_rra(stack_a, 1);
			ft_print_stacks(*stack_a, 0);
			number_of_ops_used++;
		}
	}
	ft_print_stacks(*stack_a, 0);
	return (number_of_ops_used);
}

/*
** int	ft_rotate_b_to_accept_new_element(t_dl_lst **stack_b, int elem)
** This function will rotate stack_b appropriately to accept the new element
** from the top of the stack_a. 
*/

int	ft_rotate_b_to_accept_new_element(t_dl_lst **stack_b, int elem)
{
	int	n_ops_top;
	int	next;
	int	n_ops_bottom;
	int	n_ops;

	next = ft_dl_lst_next_content(*stack_b, elem);
	if (next == elem)
		return (0);
	n_ops_bottom = ft_dl_lst_n_rrot_to_reach_elem(*stack_b, next);
	n_ops_top = ft_dl_lst_n_rot_to_reach_elem(*stack_b, next);
	n_ops = 0;
	if (n_ops_top < n_ops_bottom)
	{
		while ((*stack_b)->content != next)
		{
			ft_rb(stack_b, 1);
			ft_print_stacks(0, *stack_b);
			n_ops++;
		}
	}
	else
	{
		while ((*stack_b)->content != next)
		{
			ft_rrb(stack_b, 1);
			ft_print_stacks(0, *stack_b);
			n_ops++;
		}
	}
	ft_print_stacks(0, *stack_b);
	return (n_ops);
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
	int	n_ops;

	top_content = (*stack_a)->content;
	n_ops = 0;
	if (*stack_b)
	{
		min_in_b = ft_dl_lst_min(*stack_b);
		max_in_b = ft_dl_lst_max(*stack_b);
		if (top_content > max_in_b)
		{
			ft_pb(stack_a, stack_b, 1);
			ft_rb(stack_b, 1);
			ft_print_stacks(0, *stack_b);
			return (2);
		}
		else if (top_content < min_in_b)
		{
			ft_pb(stack_a, stack_b, 1);
			ft_print_stacks(0, *stack_b);
			return (1);
		}
		else
		{
			n_ops += ft_rotate_b_to_accept_new_element(stack_b, top_content);
			ft_pb(stack_a, stack_b, 1);
			ft_print_stacks(0, *stack_b);
			return (n_ops + 1);
		}
	}
	ft_pb(stack_a, stack_b, 1);
	ft_print_stacks(*stack_a, *stack_b);
	return (1);
}

/*
** void	ft_send_next_part_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b,
**								int *sorted_a, int n_elems)
** This function is responsible for sending the entire next "part" of stack_a
** to stack_b
*/

int	ft_send_next_part_to_b(t_dl_lst **stack_a, t_dl_lst **stack_b,
								int *next_part, int n_elems)
{
	int	parts_length;
	int	current_n_elemts;
	int	n_ops;

	n_ops = 0;
	parts_length = n_elems;
	while (*stack_a && parts_length)
	{
		n_ops += ft_put_next_elem_on_the_top_of_a(stack_a, next_part, parts_length);
		n_ops += ft_send_top_elem_to_b(stack_a, stack_b);
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

void	ft_hundred_or_less_algo(t_dl_lst **stack_a, int *sorted_a, int n_elems)
{
	t_dl_lst	*stack_b;
	int			n_ops;
	int			*next_part;
	int			current_part_offset;
	int			offset;

	n_ops = 0;
	next_part = sorted_a;
	stack_b = 0;
	current_part_offset = 0;
	offset = n_elems / N_PARTS_UNDER_HUNDRED;
	while (*stack_a)
	{
		n_ops += ft_send_next_part_to_b(stack_a, &stack_b, next_part, offset);
		current_part_offset += offset;
		if (current_part_offset >= n_elems)
			break ;
		next_part = &(next_part[offset]);
	}
	while (stack_b)
	{
		ft_pa(&stack_b, stack_a, 1);
		n_ops++;
	}
	ft_print_stacks(*stack_a, stack_b);
	printf("n_ops under 100: [%d]\n", n_ops);
}
