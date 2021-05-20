/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:26:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 17:42:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_input_error(void)
{
	ft_putendl("Error");
	return (-1);
}

int	ft_found_bad_input(int argc, char **argv)
{
	int 			i;
	unsigned int	argv_after_atou;
	int				tab[argc - 1];
	int				tab_size;

	i = 1;
	tab_size = 0;
	while (i < argc)
	{
		if (!ft_str_is_number(argv[i]))
			return (1);
		argv_after_atou = ft_atou(argv[i]);
		if (argv_after_atou > INT_MAX || argv_after_atou < (unsigned int)(INT_MIN))
			return (1);
		if (ft_element_found_in_int_tab(argv_after_atou, tab, tab_size))
			return (1);
		tab[tab_size] = argv_after_atou;
		tab_size++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_dl_lst	*stack_a;
	t_dl_lst	*stack_b;
	int			tab[argc - 1];
	int			i;
	int			j;

	i = 1;
	j = 0;
	if (ft_found_bad_input(argc, argv))
		return (ft_input_error());
	while (i < argc)
		tab[j] = ft_atoi(argv[i]);
	if (argc < 3 || ft_int_tab_is_sorted(tab, argc - 1, 1))
	{
		ft_putendl("Sorted!");
		return (1);
	}
	return (0);
}