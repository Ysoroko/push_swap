/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:44:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 15:54:19 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
** 1st argument = top of the stack
** 
*/

int	main(int argc, char **argv)
{
	t_dl_lst	*stack_a;
	t_dl_lst	*current_t_dl_lst;
	int			tab[argc - 1];
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (argc < 3)
		return (0);
	if (ft_found_bad_input(argc, argv))
		return (ft_putendl_color("Error", BOLD_RED, -1));
	while (++i < argc)
		tab[j++] = ft_atoi(argv[i]);
	stack_a = ft_dl_lst_new_exit(tab[0]);
	i = 1;
	current_t_dl_lst = stack_a;
	while (i < argc - 1)
	{
		ft_dl_lst_add_back(&current_t_dl_lst, ft_dl_lst_new_exit(tab[i]));
		current_t_dl_lst = current_t_dl_lst->next;
		i++;
	}
	if (checker(&stack_a) == -1)
		return (ft_putendl_color("Error", BOLD_RED, -1));
	return (0);
}
