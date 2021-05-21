/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:26:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 15:00:33 by ysoroko          ###   ########.fr       */
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
		if (argv_after_atol > INT_MAX || argv_after_atol < (INT_MIN))
			return (1);
		if (ft_element_found_in_int_tab(argv_after_atol, tab, tab_size))
			return (1);
		tab[tab_size] = argv_after_atol;
		tab_size++;
		i++;
	}
	return (0);
}

t_dl_lst	*ft_push_swap(t_dl_lst *stack_a)
{
	t_dl_lst	*stack_b;
	int			number_of_operations;
	int			current_value;

	while (!ft_dl_lst_is_sorted(stack_a, 1))
	{
		ft_putstr("ok");
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
		tab[j] = ft_atoi(argv[i]);
	if (argc < 3 || ft_int_tab_is_sorted(tab, argc - 1, 1))
	{
		ft_putendl("Sorted!");
		return (1);
	}
	stack_a = ft_dl_lst_new_exit(ft_atoi(argv[1]));
	i = 2;
	current_t_dl_lst = stack_a;
	while (i < argc)
	{
		ft_dl_lst_add_back(current_t_dl_lst, ft_dl_lst_new_exit(ft_atoi(argv[i])));
		current_t_dl_lst = current_t_dl_lst->next;
	}
	return (0);
}