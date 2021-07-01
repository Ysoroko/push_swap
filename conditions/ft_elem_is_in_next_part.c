/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_is_in_next_part.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:27:49 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/01 12:31:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_elem_is_in_next_part(t_dl_lst *stack_a, int *next_part, int p_size)
{
	int	content;
	int	i;

	i = -1;
	content = stack_a->content;
	while (++i < p_size)
	{
		if (content == next_part[i])
			return (1);
	}
	return (0);
}
