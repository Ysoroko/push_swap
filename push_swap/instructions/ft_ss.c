/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:24:25 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/07 14:09:26 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ss(t_dl_lst **stack_a, t_dl_lst **stack_b)
{
	if (stack_a && stack_b)
	{
		ft_sa(stack_a, 0);
		ft_sb(stack_b, 0);
		ft_putendl("ss");
	}
}