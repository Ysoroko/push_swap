/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:26:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 14:13:48 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

/*
** int	ft_found_bad_input_multi_argv(int argc, char **argv)
** This function is responsible for detecting forbidden chars in main arguments
** It is used when there are multiple argv, each representing a separate
** number which will be used in push_swap
** Returns 1 if bad input was found, 0 otherwise
*/

static int	ft_found_bad_input_multi_argv(int argc, char **argv)
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
		if (argv_after_atol > INT_MAX || argv_after_atol < INT_MIN)
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
** static int	*ft_multiple_argv(int argc, char **argv)
** This function transforms user input into a tab of ints.
** Returns NULL pointer if an error was found in user input or the newly
** created int array otherwise.
*/

static int	*ft_multiple_argv(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		exit(EXIT_FAILURE);
	if (ft_found_bad_input_multi_argv(argc, argv))
	{
		free(tab);
		return (NULL);
	}
	while (++i < argc)
		tab[j++] = ft_atoi(argv[i]);
	return (tab);
}

/*
** static int ft_found_bad_input_single_argv(char *input)
** This function is responsible for checking of bad input inside single argv.
** Bad input includes:
** 1) Characters other than " -0123456789" are present.
** 2) "-" character is present and is placed in the middle/at the end of a num
*/

static int ft_found_bad_input_single_argv(char *input, int **tab)
{
	int		i;
	char	**input_as_str_tab;
	long	elem_after_atol;

	i = -1;
	while (input[++i])
	{
		if (!ft_strchr(ALLOWED_CHARS_SINGLE_ARGV, input[i]))
			return (1);
	}
	input_as_str_tab = ft_split(input, ' ');
	if (!input_as_str_tab)
		exit(EXIT_FAILURE);
	i = -1;
	while (input_as_str_tab[++i])
	{
		if (!ft_str_is_number(input_as_str_tab[i]))
			return (ft_free_str_tab(input_as_str_tab, 1));
		elem_after_atol = ft_atol(input_as_str_tab[i]);
		if (elem_after_atol > INT_MAX || elem_after_atol < INT_MIN)
			return (ft_free_str_tab(input_as_str_tab, 0));
		(*tab)[i] = ft_atoi(input_as_str_tab[i]);
	}
	return (0);
}

/*
** static int	*ft_single_argv(char **argv)
** This function is used when there is a single main argument with all the
** numbers needed to be sorted separated by spaces.
*/

static int	*ft_single_argv(char **argv)
{
	char	*input;
	int		*tab;
	int		len;

	input = argv[1];
	len = ft_n_ints_in_str(input);
	tab = malloc(sizeof(int) * len);
	if (ft_found_bad_input_single_argv(input, &tab))
		return (NULL);
	return (tab);
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

	if (argc == 2)
		tab = ft_single_argv(argv);
	else
		tab = ft_multiple_argv(argc, argv);
	if (!tab)
		return (ft_putendl_color("Error", BOLD_RED, 1, STDERR));
	if (ft_int_tab_is_sorted(tab, argc - 1, 1))
		return (ft_free_int_tab(&tab, 1));
	stack_a = ft_dl_lst_new_exit(tab[0]);
	i = 0;
	while (++i < argc - 1)
		ft_dl_lst_add_back(&stack_a, ft_dl_lst_new_exit(tab[i]));
	free(tab);
	ft_determine_and_apply_algo(&stack_a);
	ft_dl_lstclear(stack_a);
	//system("leaks push_swap");
	return (0);
}
