/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred_or_less_algo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:43:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/03 16:46:50 by ysoroko          ###   ########.fr       */
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

int	ft_put_next_elem_on_the_top_of_a(t_dl_lst **stack_a, t_dl_lst **stack_b, int **part, int ln)
{
	int	next_elem_from_top;
	int	next_elem_bottom;
	int	n_ops_top;
	int	n_ops_bottom;
	int	number_of_ops_used;

	number_of_ops_used = 0;
	ft_print_next_part(*part, ln);
	printf("before next elem from top\n");
	next_elem_from_top = ft_first_elem_from_next_part_top(*stack_a, *stack_b, *part, ln);
	printf("before next elem from bottom\n");
	next_elem_bottom = ft_first_elem_from_next_prt_bottom(*stack_a, *stack_b, *part, ln);
	printf("next elem top: [%d]\n", next_elem_from_top);
	printf("next elem bottom: [%d]\n", next_elem_bottom);
	if (!ft_int_elem_is_in_next_part(next_elem_from_top, *part, ln) || !ft_int_elem_is_in_next_part(next_elem_bottom, *part, ln))
	{
		printf("elem not in next part bottom or top!\n");
		return (0);
	}
	n_ops_top = ft_number_of_moves_from_the_top(*stack_a, next_elem_from_top);
	printf("first elem from top ops: [%d]\n", n_ops_top);
	n_ops_bottom = ft_number_of_moves_from_the_bottom(*stack_a, next_elem_bottom);
	printf("first elem from bottom ops: [%d]\n", n_ops_bottom);
	ft_print_stacks(*stack_a, 0);
	if (n_ops_top <= n_ops_bottom)
	{
		while (*stack_a && (*stack_a)->content != next_elem_from_top)
		{
			// ft_print_next_part(part, ln);
			ft_ra(stack_a, 1);
			// ft_print_stacks(*stack_a, 0);
			number_of_ops_used++;
		}
	}
	else
	{
		while (*stack_a && (*stack_a)->content != next_elem_bottom)
		{
			// ft_print_next_part(part, ln);
			ft_rra(stack_a, 1);
			//ft_print_stacks(*stack_a, 0);
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
	printf("next elem after the one Im receiving in b: [%d]\n", next);
	if (next == elem)
	{
		printf("next = elem!\n");
		return (0);
	}
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
		n_ops += ft_rotate_b_to_accept_new_element(stack_b, top_content);
		ft_pb(stack_a, stack_b, 1);
		ft_print_stacks(0, *stack_b);
		return (n_ops + 1);
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
								int **next_part, int n_elems)
{
	int	parts_length;
	int	current_n_elemts;
	int	n_ops;

	n_ops = 0;
	parts_length = n_elems;
	while (*stack_a && parts_length)
	{
		//printf("going to put next elem on top of a now\n");
		n_ops += ft_put_next_elem_on_the_top_of_a(stack_a, stack_b, next_part, n_elems);
		//printf("top of stack a after putting next elem on top: [%d]\n", (*stack_a)->content);
		n_ops += ft_send_top_elem_to_b(stack_a, stack_b);
		//printf("sent top of a to b now\n");
		parts_length--;
		printf("parts_len after decrementing: [%d]\n", parts_length);
	}
	printf("next part sent to b!\n");
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
	printf("SORTED_A:\n");
	ft_print_next_part(sorted_a, n_elems);
	while (*stack_a && current_part_offset < n_elems)
	{
		//printf("\n\n\n");
		//printf("next part at the start\n");
		//ft_print_next_part(next_part, offset);
		//printf("\n\n\n");
		next_part = &(sorted_a[current_part_offset]);
		printf("\n\n\n");
		printf("next part after nexting:\n");
		ft_print_next_part(next_part, offset);
		printf("\n\n\n");
		n_ops += ft_send_next_part_to_b(stack_a, &stack_b, &next_part, offset);
		if (current_part_offset >= n_elems)
			break ;
		if (ft_int_elem_is_in_next_part(sorted_a[n_elems - 1], next_part, offset))
		{
			printf("offset modified!\n");
			offset = ft_index_of_element_in_int_tab(sorted_a[n_elems], next_part, offset);
		}
		current_part_offset += offset;
		printf("current_part_offset: [%d]\n", current_part_offset);
		
	}
	while (ft_dl_lst_last(stack_b)->content != sorted_a[0])
	{
		ft_rb(&stack_b, 1);
		n_ops++;
	}
	while (stack_b)
	{
		ft_pa(&stack_b, stack_a, 1);
		n_ops++;
	}
	ft_print_stacks(*stack_a, stack_b);
	printf("n_ops under 100: [%d]\n", n_ops);
}
