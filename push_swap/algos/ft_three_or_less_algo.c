/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_or_less_algo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:50:31 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/10 16:08:46 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** void	ft_apply_instructions(t_dl_lst **stack_a, int first, int second)
** This function does all the instructions needed to sort the *stack_a
*/

static void	ft_apply_instructions(t_dl_lst **stack_a, int first, int second)
{
	int	third;

	third = (((*stack_a)->next)->next)->content;
	if (first < second && first < third && second > third)
	{
		ft_rra(stack_a, 1);
		ft_sa(stack_a, 1);
	}
	else if (first > second && first > third && second > third)
	{
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if (first > second && first > third && second < third)
	{
		ft_ra(stack_a, 1);
	}
	else if (first > second && first < third)
		ft_sa(stack_a, 1);
	else if (first < second && first > third)
		ft_rra(stack_a, 1);
}

/*
** void	ft_three_or_less_algo(t_dl_lst **stack_a)
** This is the algorith used if *stack_a has 3 or less elements
** A very specific optimisation is required here so the instructions are
** hard coded one by one in "ft_apply_instructions"
*/

void	ft_three_or_less_algo(t_dl_lst **stack_a)
{
	int	first;
	int	second;
	int	n_elems;

	if (!stack_a || !*stack_a)
		return ;
	first = (*stack_a)->content;
	second = ((*stack_a)->next)->content;
	n_elems = ft_dl_lst_size(*stack_a);
	if (n_elems == 2)
		ft_sa(stack_a, 1);
	else
		ft_apply_instructions(stack_a, first, second);
}
