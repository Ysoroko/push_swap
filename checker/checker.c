/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:16:52 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/07 16:04:32 by ysoroko          ###   ########.fr       */
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

	current_a = ft_dl_lst_first(stack_a);
	current_b = ft_dl_lst_first(stack_b);
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
		if (current_a)
		{
			if (current_a == ft_dl_lst_first(stack_a))
			{
				separator = top;
				printf(BOLD_MAGENTA);
				width = 19;
			}
			else if (current_a == ft_dl_lst_last(stack_a))
			{
				printf("\n");
				separator = bottom;
				printf(BOLD_CYAN);
				width = 18;
			}
			printf("%-*d%s", width, current_a->content, separator);
			if (current_a == ft_dl_lst_first(stack_a) && !current_b)
				printf("\n");
			current_a = current_a->next;
			printf(COLOR_RESET);
			separator = "|";
			width = 20;
		}
		if (current_b)
		{
			if (current_b == ft_dl_lst_first(stack_b))
				printf(BOLD_MAGENTA);
			else if (current_b == ft_dl_lst_last(stack_b))
				printf(BOLD_CYAN);
			printf("%*d\n", width, current_a->content);
			if (current_b == ft_dl_lst_first(stack_b))
				printf("\n");
			current_b = current_b->next;
			printf(COLOR_RESET);
		}

		printf("\n");
	}
	printf("\n\n\n");
}

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
		ft_pb(stack_a, stack_b);
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
	return (0);
}

int	checker(t_dl_lst **stack_a)
{
	t_dl_lst	*stack_b;
	int			ret;

	stack_b = 0;
	while (!ft_stack_a_is_sorted(*stack_a) || stack_b)
	{
		ft_print_stacks(*stack_a, stack_b);
		ret = ft_read_input_and_execute(stack_a, &stack_b);
		if (ret == -1)
		{
			free(stack_b);
			return (-1);
		}
	}
	return (0);
}
