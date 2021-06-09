/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:16:52 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 15:38:36 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_print_stacks(t_dl_lst *stack_a, t_dl_lst *stack_b)
{
	int			width;
	t_dl_lst	*current_a;
	t_dl_lst	*current_b;
	char		*separator = "|";
	char		*top = "TOP";
	char		*bottom = "BOTTOM";

	current_a = stack_a;
	current_b = stack_b;
	width = 20;
	printf("\n\n\n");
	printf(BOLD_WHITE);
	for (int i = 0; i <= 2 * width; i++)
		printf("-");
	printf(BOLD_YELLOW);
	printf("\n%-*s|%*s\n", width, "STACK A", width, "STACK B");
	printf(BOLD_WHITE);
	for (int i = 0; i <= 2 * width; i++)
		printf("-");
	printf("\n\n");
	printf(COLOR_RESET);
	while (current_a || current_b)
	{
		if (!current_a && current_b)
		{
			if (current_b == ft_dl_lst_last(stack_b))
			{
				printf("\n");
				printf(BOLD_CYAN);
				separator = bottom;
				width = 23;
			}
			else if (current_b == ft_dl_lst_first(stack_b))
			{
				printf(BOLD_MAGENTA);
				separator = top;
				width = 22;
			}
			else
				width = 21;
			printf("%*s", width, separator);
			width = 20;
		}
		if (current_a)
		{
			if (current_a == stack_a)
			{
				separator = top;
				printf(BOLD_MAGENTA);
				width = 19;
			}
			else if (current_a == ft_dl_lst_last(stack_a))
			{
				printf("\n");
				if (!current_b || current_b == ft_dl_lst_last(stack_b))
				{
					separator = bottom;
					width = 18;
				}
				printf(BOLD_CYAN);
			}
			if (current_b && current_b != stack_b && current_b == ft_dl_lst_last(stack_b)
					&& current_a != stack_a->next)
				printf("\n");
			printf("%-*d%s", width, current_a->content, separator);
			if (current_a == stack_a && !current_b)
				printf("\n");
			current_a = current_a->next;
			printf(COLOR_RESET);
			separator = "|";
		}
		if (current_b)
		{
			if (current_b == stack_b)
			{
				width = 19;
				printf(BOLD_MAGENTA);
			}
			else if (current_b == ft_dl_lst_last(stack_b))
			{
				width = 20;
				if (ft_dl_lst_current_index(stack_b, current_b) == ft_dl_lst_size(stack_a))
					width = 17;
				if (!current_a)
					width = 18;
				printf(BOLD_CYAN);
			}
			printf("%*d", width, current_b->content);
			if (current_b == stack_b)
				printf("\n");
			current_b = current_b->next;
			printf(COLOR_RESET);
		}
		width = 20;
		separator = "|";
		printf("\n");
	}
	printf("\n\n\n");
}

static int ft_execute(char	*input_str, t_dl_lst **stack_a, t_dl_lst **stack_b)
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
	ft_print_stacks(*stack_a, stack_b);
	ret = ft_read_input_and_execute(stack_a, &stack_b);
	while (ret > 0)
	{
		ft_print_stacks(*stack_a, stack_b);
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
			return (ft_putendl_color("OK", BOLD_GREEN, 1));
		else
			return (ft_putendl_color("KO", BOLD_RED, 1));
	}
	return (-1);
}
