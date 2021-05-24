/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:26:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 10:40:25 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_input_error(void)
{
	ft_putstr(BOLD_RED);
	ft_putendl("Error");
	ft_putstr(COLOR_RESET);
	return (-1);
}

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
		printf("argv_after_atol: [%ld]\n", argv_after_atol);
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

static void	ft_print_dl_lst(t_dl_lst *lst)
{
	t_dl_lst	*current;
	int			i;

	i = 1;
	current = ft_dl_lst_first(lst);
	printf("\n\n\n");
	while (current)
	{
		printf("|%-5d|%10d\n", i, current->content);
		i++;
		current = current->next;
	}
	printf("\n\n\n");
}


/*
** Logic:
** sa: swap 2 first elements of a
** sb: swap 2 first elements of b
** ss: swap first 2 elements of both a and b
** pa: push first element of b to the top of a
** pb: push first element of a to the top of b
** ra: rotate a (1st element becomes the last one)
** rb: rotate b (1st element becomes the last one)
** rr: rotate a and b (1st elements become last)
** rra: reverse rotate a (last element becomes the 1st one)
** rrb: reverse rotate a (last element becomes the 1st one)
** rrr: reverse rotate a and b (last elements become 1st)
**
**
** If |a......b|	a > b	
**
*/

t_dl_lst	*ft_push_swap(t_dl_lst *stack_a)
{
	t_dl_lst	*stack_b;
	int			number_of_operations;
	int			current_value;
	int			initial_stack_a_size;

	initial_stack_a_size = ft_dl_lst_size(stack_a);
	while (ft_dl_lst_size(stack_a) >= initial_stack_a_size / 2)
		ft_pb(stack_a, &stack_b);
	while (!ft_dl_lst_is_sorted(stack_a, 1) && !ft_dl_lst_is_sorted(stack_b, 0))
	{
		
	}
	return (0);
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
		return (ft_input_error());
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
		ft_dl_lst_add_back(current_t_dl_lst, ft_dl_lst_new_exit(tab[i]));
		current_t_dl_lst = current_t_dl_lst->next;
		i++;
	}
	ft_print_dl_lst(stack_a);
	return (0);
}