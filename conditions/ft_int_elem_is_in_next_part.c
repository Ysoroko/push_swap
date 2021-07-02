/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_elem_is_in_next_part.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:08:50 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/02 14:19:45 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_int_elem_is_in_next_part(int n, int *next_part, int p_size)
** This function returns 1 if the element n is present in next_part int tab.
** Returns 1 if the element is found, 0 if it is not
*/

int	ft_int_elem_is_in_next_part(int n, int *next_part, int p_size)
{
	int	i;

	i = -1;
	while (++i < p_size)
	{
		if (n == next_part[i])
			return (1);
	}
	return (0);
}
