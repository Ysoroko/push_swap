/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:44:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 15:32:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_found_bad_input(int argc, char **argv)
{
	int		i;
	long	argv_after_atol;
	int		*tab;
	int		tab_size;

	i = 1;
	tab_size = 0;
	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		if (!ft_str_is_number(argv[i]))
			return (ft_free_int_tab(&tab, 1));
		argv_after_atol = ft_atol(argv[i]);
		if (argv_after_atol > INT_MAX || argv_after_atol < (INT_MIN))
			return (ft_free_int_tab(&tab, 1));
		if (ft_element_found_in_int_tab(argv_after_atol, tab, tab_size))
			return (ft_free_int_tab(&tab, 1));
		tab[tab_size] = argv_after_atol;
		tab_size++;
		i++;
	}
	return (ft_free_int_tab(&tab, 0));
}

static void	ft_input_to_stack_a(t_dl_lst **stack_a, int *tab, int argc)
{
	t_dl_lst	*current;
	int			i;

	i = 0;
	*stack_a = ft_dl_lst_new_exit(tab[0]);
	current = *stack_a;
	while (++i < argc - 1)
	{
		ft_dl_lst_add_back(&current, ft_dl_lst_new_exit(tab[i]));
		current = current->next;
	}
}

/*
** 1st argument = top of the stack
** 
*/

int	main(int argc, char **argv)
{
	t_dl_lst	*stack_a;
	t_dl_lst	*current_t_dl_lst;
	int			*tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab || argc < 3)
		return (ft_free_int_tab(&tab, 0));
	if (ft_found_bad_input(argc, argv))
	{
		ft_free_int_tab(&tab, 0);
		return (ft_putendl_color("Error", BOLD_RED, -1, STDERR));
	}
	while (++i < argc)
		tab[j++] = ft_atoi(argv[i]);
	ft_input_to_stack_a(&stack_a, tab, argc);
	if (checker(&stack_a) == -1)
		return (ft_putendl_color("Error", BOLD_RED, -1, STDERR));
	return (ft_free_int_tab(&tab, 0));
}
