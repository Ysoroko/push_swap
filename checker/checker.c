/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:16:52 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/07 13:33:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int ft_execute(char	*input_str, t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	if (!ft_strlcmp(input_str, "sa"))
		ft_sa(stack_a, 1);
	else if (!ft_strlcmp(input_str, "sb"))
		ft_sb(stack_b, 1);
	else if (!ft_strlcmp(input_str, "ss"))
		ft_ss(stack_a, stack_b);
	else if (!ft_strlcmp(input_str, "pa"))
		ft_pa(stack_a, stack_b);
	else if (!ft_strlcmp(input_str, "pb"))
		ft_pb(stack_b, stack_a);
	else if (!ft_strlcmp(input_str, "ra"))
		ft_ra(stack_a, 1);
	else if (!ft_strlcmp(input_str, "rb"))
		ft_rb(stack_b, 1);
	else if (!ft_strlcmp(input_str, "rr"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strlcmp(input_str, "rra"))
		ft_rra(stack_a, 1);
	else if (!ft_strlcmp(input_str, "rrb"))
		ft_rrb(stack_b, 1);
	else if (!ft_strlcmp(input_str, "rrr"))
		ft_rrr(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

static int	ft_read_input_and_execute(t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	char	*input;

	input = ft_calloc(sizeof(char), INPUT_SIZE);
	if (read(1, input, INPUT_SIZE) < 0)
	{
		free(input);
		return (-1);
	}
	if (ft_execute(input, stack_a, stack_b) == -1)
	{
		free(input);
		return (-1);
	}
	free(input);
	return (0);
}

int	checker(t_dl_lst **stack_a)
{
	t_dl_lst	*stack_b;
	int			ret;

	stack_b = 0;
	while (!ft_stack_a_is_sorted(stack_a) && !stack_b)
	{
		ret = ft_read_input_and_execute(stack_a, &stack_b);
		if (ret == -1)
		{
			free(stack_b);
			return (-1);
		}
	}
}
