/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:26:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/13 15:40:20 by ysoroko          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_dl_lst	*stack_a;
	int			tab[argc - 1];
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (ft_found_bad_input(argc, argv))
		return (ft_putendl_color("Error\n", BOLD_RED, -1));
	while (++i < argc)
		tab[j++] = ft_atoi(argv[i]);
	if (argc < 3 || ft_int_tab_is_sorted(tab, argc - 1, 1))
	{
		ft_putendl("Sorted!");
		return (1);
	}
	stack_a = ft_dl_lst_new_exit(tab[0]);
	i = 0;
	while (++i < argc - 1)
		ft_dl_lst_add_back(&stack_a, ft_dl_lst_new_exit(tab[i]));
	ft_determine_and_apply_algo(&stack_a);
	return (0);
}
