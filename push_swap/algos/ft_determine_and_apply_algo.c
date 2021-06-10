/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine_algo_to_use.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:50:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/10 15:09:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_determine_and_apply_algo(t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	int		ret;
	int		n_elems;

	n_elems = ft_dl_lst_size(*stack_a);
	if (n_elems <= 3)
		ft_three_or_less_algo(stack_a);
}
