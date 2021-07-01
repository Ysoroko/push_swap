/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_chars_in_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:30:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/08 15:33:15 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_n_chars_in_int(int n)
** This function returns the number of chars necessary to write n
** as a string
*/

int	ft_n_chars_in_int(int n)
{
	int	m;
	int	count;

	count = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		m = -n;
		count++;
	}
	else
		m = n;
	while (m % 10)
	{
		m = m / 10;
		count++;
	}
	return (count);
}
