/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:17:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/04 12:04:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_stacks(t_dl_lst *stack_a, t_dl_lst *stack_b)
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
	printf("\n\n");
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
	printf("\n\n");
}