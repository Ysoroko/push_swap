/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:16:52 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 15:32:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_execute(char	*input_str, t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	if (!ft_strlcmp(input_str, "sa"))
		ft_sa(stack_a, 0);
	else if (!ft_strlcmp(input_str, "sb"))
		ft_sb(stack_b, 0);
	else if (!ft_strlcmp(input_str, "ss"))
		ft_ss(stack_a, stack_b, 0);
	else if (!ft_strlcmp(input_str, "pa"))
		ft_pa(stack_b, stack_a, 0);
	else if (!ft_strlcmp(input_str, "pb"))
		ft_pb(stack_a, stack_b, 0);
	else if (!ft_strlcmp(input_str, "ra"))
		ft_ra(stack_a, 0);
	else if (!ft_strlcmp(input_str, "rb"))
		ft_rb(stack_b, 0);
	else if (!ft_strlcmp(input_str, "rr"))
		ft_rr(stack_a, stack_b, 0);
	else if (!ft_strlcmp(input_str, "rra"))
		ft_rra(stack_a, 0);
	else if (!ft_strlcmp(input_str, "rrb"))
		ft_rrb(stack_b, 0);
	else if (!ft_strlcmp(input_str, "rrr"))
		ft_rrr(stack_a, stack_b, 0);
	else
		return (-1);
	return (0);
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
	if (ft_execute(input, stack_a, stack_b) == -1)
	{
		free(input);
		return (-1);
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
		if (ret == -1)
		{
			free(stack_b);
			return (-1);
		}
		ret = ft_read_input_and_execute(stack_a, &stack_b);
	}
	if (ret <= 0)
	{
		if (ft_stack_a_is_sorted(*stack_a) && !stack_b)
			return (ft_putendl_color("OK", BOLD_GREEN, 1, 1));
		else
		{
			ft_dl_lstclear(stack_b);
			return (ft_putendl_color("KO", BOLD_RED, 1, 1));
		}
	}
	return (-1);
}
