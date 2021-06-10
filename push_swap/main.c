/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:26:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/10 12:24:44 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_found_bad_input(int argc, char **argv)
{
	int		i;
	long	argv_after_atol;
	int		tab[argc - 1];
	int		tab_size;

	i = 1;
	tab_size = 0;
	while (i < argc)
	{
		if (!ft_str_is_number(argv[i]))
			return (1);
		argv_after_atol = ft_atol(argv[i]);
		//printf("argv_after_atol: [%ld]\n", argv_after_atol);
		if (argv_after_atol > INT_MAX || argv_after_atol < (INT_MIN))
		{
			printf("outside int limits\n");
			return (1);
		}
		if (ft_element_found_in_int_tab(argv_after_atol, tab, tab_size))
		{
			printf("Duplicates\n");
			return (1);
		}
		tab[tab_size] = argv_after_atol;
		tab_size++;
		i++;
	}
	return (0);
}

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

	if (!stack_a || min_dl_lst)
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
		while ((*stack_a)->content != min_value)
		{
			if (ft_top_two_elems_to_swap(*stack_a))
			{
				ft_sa(stack_a, 1);
				(*n_op)++;
			}
			ft_ra(stack_a, 1);
			(*n_op)++;
		}
	}
	else
	{
		while ((*stack_a)->content != min_value)
		{
			if (ft_top_two_elems_to_swap(*stack_a))
			{
				ft_sa(stack_a, 1);
				(*n_op)++;
			}
			ft_rra(stack_a, 1);
			(*n_op)++;
		}
	}
	ft_pb(stack_a, stack_b, 1);
	(*n_op)++;
}

void	ft_push_swap(t_dl_lst **stack_a)
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
		if (ft_stack_a_is_sorted(*stack_a))
		{
			//printf("sorted after sa\n");
			break ;
		}
		ft_print_stacks(*stack_a, stack_b);
		ft_send_min_to_b(stack_a, &stack_b, &number_of_operations);
		ft_print_stacks(*stack_a, stack_b);
	}
	while (stack_b)
	{
		ft_pa(&stack_b, stack_a, 1);
		number_of_operations++;
	}
	printf("Number of operations: [%d]\n", number_of_operations);
}

int	main(int argc, char **argv)
{
	t_dl_lst	*stack_a;
	t_dl_lst	*current_t_dl_lst;
	int			tab[argc - 1];
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (ft_found_bad_input(argc, argv))
		return (ft_putendl_color("Error\n", BOLD_RED, -1));
	while (++i < argc)
	{
		tab[j] = ft_atoi(argv[i]);
		j++;
	}
	if (argc < 3 || ft_int_tab_is_sorted(tab, argc - 1, 1))
	{
		ft_putendl("Sorted!");
		return (1);
	}
	stack_a = ft_dl_lst_new_exit(tab[0]);
	i = 1;
	current_t_dl_lst = stack_a;
	while (i < argc - 1)
	{
		ft_dl_lst_add_back(&current_t_dl_lst, ft_dl_lst_new_exit(tab[i]));
		current_t_dl_lst = current_t_dl_lst->next;
		i++;
	}
	ft_push_swap(&stack_a);
	return (0);
}
//at the top of stack A we need to have the minimal value!


/*
** Logic of the algorithm:
** 1) All the arguments are put in stack A, stack B is empty
** 2) Check the first 2 elements of A, if 1st < 2nd -> swap them with "sa"
** 3) We look for the minimum value in stack_a
** 		+ check if it's in 1st or 2nd half of the stack
** 4) Put the minimum value at the top of the stack A
** 		- If it's in the 1st half of stack A, we use "ra"
** 		- If it's in the 2nd half is stack A, we use "rra"
** 5) Push the minimum value to stack B
** 6) If stack A is already sorted, push everything from stack B to stack A
** 6) Repeat step 2)
*/