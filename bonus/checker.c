/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:16:52 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 16:59:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_execute(char	*input_str, t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	if (!ft_strlcmp(input_str, "sa"))
		return (ft_sa(stack_a, 0));
	else if (!ft_strlcmp(input_str, "sb"))
		return (ft_sb(stack_b, 0));
	else if (!ft_strlcmp(input_str, "ss"))
		return (ft_ss(stack_a, stack_b, 0));
	else if (!ft_strlcmp(input_str, "pa"))
		return (ft_pa(stack_b, stack_a, 0));
	else if (!ft_strlcmp(input_str, "pb"))
		return (ft_pb(stack_a, stack_b, 0));
	else if (!ft_strlcmp(input_str, "ra"))
		return (ft_ra(stack_a, 0));
	else if (!ft_strlcmp(input_str, "rb"))
		return (ft_rb(stack_b, 0));
	else if (!ft_strlcmp(input_str, "rr"))
		return (ft_rr(stack_a, stack_b, 0));
	else if (!ft_strlcmp(input_str, "rra"))
		return (ft_rra(stack_a, 0));
	else if (!ft_strlcmp(input_str, "rrb"))
		return (ft_rrb(stack_b, 0));
	else if (!ft_strlcmp(input_str, "rrr"))
		return (ft_rrr(stack_a, stack_b, 0));
	else if (!ft_strlcmp(input_str, ""))
		return (-1);
	return (-2);
}

static int	ft_read_input_and_execute(t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	char	*input;
	int		read_ret;

	input = ft_calloc(sizeof(char), INPUT_SIZE);
	read_ret = read(1, input, INPUT_SIZE);
	if (read_ret < 0)
	{
		free(input);
		return (-1);
	}
	input[read_ret - 1] = 0;
	if (ft_execute(input, stack_a, stack_b) == -2)
	{
		free(input);
		return (-2);
	}
	free(input);
	return (read_ret);
}

int	checker(t_dl_lst **stack_a)
{
	t_dl_lst	*stack_b;
	int			ret;

	stack_b = 0;
	ret = ft_read_input_and_execute(stack_a, &stack_b);
	while (ret > 0)
	{
		ret = ft_read_input_and_execute(stack_a, &stack_b);
	}
	if (ret <= 0 && ret != -2)
	{
		ft_print_stacks(*stack_a, 0);
		if (ft_stack_a_is_sorted(*stack_a) && !stack_b)
			return (ft_putendl_color("OK", BOLD_GREEN, 1, STDOUT));
		else
		{
			ft_dl_lstclear(stack_b);
			return (ft_putendl_color("KO", BOLD_RED, 1, STDOUT));
		}
	}
	return (-1);
}
