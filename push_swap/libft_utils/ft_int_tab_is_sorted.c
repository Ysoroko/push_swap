/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_is_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:21:49 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 10:39:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_int_tab_is_sorted(int *tab, int tab_len, int low_to_high)
** This function checks if tab (an array of ints) is sorted or not
** If low_to_high argument is 0, it checks if the array is sorted from
** highest to lowest integer
** If low_to_high argument is different from 0, it checks if the array is
** sorted from lowest to highest integer
** Returns 1 if the array is sorted in the specified order, 0 otherwise
*/

int	ft_int_tab_is_sorted(int *tab, int tab_len, int low_to_high)
{
	int	i;

	i = 1;
	if (!tab)
		return (0);
	if (tab_len <= 1)
		return (1);
	while (i < tab_len)
	{
		if (low_to_high)
		{
			if (tab[i] < tab[i - 1])
				return (0);
		}
		else
		{
			if (tab[i] > tab[i - 1])
				return (0);
		}
		i++;
	}
	return (1);
}
