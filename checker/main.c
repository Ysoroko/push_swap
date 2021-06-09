/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:44:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 14:17:25 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_print_dl_lst(t_dl_lst *lst, int stack_a)
{
	t_dl_lst	*current;
	int			i;

	i = 1;
	if (stack_a)
		printf("[%20s]\n", "STACK A");
	else
		printf("[%20s]\n", "STACK B");
	if (!lst)
		printf("empty pointer dl_lst\n");
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
	if (ft_found_bad_input(argc, argv))
		return (ft_input_error());
	while (++i < argc)
	{
		tab[j] = ft_atoi(argv[i]);
		j++;
	}
	if (argc < 3 || ft_int_tab_is_sorted(tab, argc - 1, 1))
	{
		ft_putstr(BOLD_GREEN);
		ft_putendl("Sorted!");
		ft_putstr(COLOR_RESET);
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
	if (checker(&stack_a) == -1)
		return (ft_input_error());
	return (0);
}
