/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:26:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/05 12:21:55 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_found_bad_input(int argc, char **argv)
{
	int		i;
	long	argv_after_atol;
	int		*tab;
	int		tab_size;

	i = 1;
	tab_size = 0;
	tab = malloc(sizeof(int) * (argc - 1));
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

/*
** Limits:
** 3 elements: 2 or 3 operations max
** 5 elements: 12 max (8 = very good) (elements used: 1 5 2 4 3)
** 100 elements: <700 = 5/5	<1500 = 1/5
** 500 elements: <5500 = 5/5	<11500 = 1/5
*/

int	main(int argc, char **argv)
{
	t_dl_lst	*stack_a;
	int			*tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * (argc - 1));
	if (ft_found_bad_input(argc, argv))
	{
		free(tab);
		return (ft_putendl_color("Error", BOLD_RED, -1));
	}
	while (++i < argc)
		tab[j++] = ft_atoi(argv[i]);
	if (argc < 3 || ft_int_tab_is_sorted(tab, argc - 1, 1))
		return (ft_free_int_tab(&tab, 1));
	stack_a = ft_dl_lst_new_exit(tab[0]);
	i = 0;
	while (++i < argc - 1)
		ft_dl_lst_add_back(&stack_a, ft_dl_lst_new_exit(tab[i]));
	free(tab);
	ft_determine_and_apply_algo(&stack_a);
	ft_dl_lstclear(stack_a);
	system("leaks push_swap");
	return (0);
}
