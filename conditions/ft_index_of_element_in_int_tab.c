/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of_element_in_int_tab.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:41:45 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/03 13:43:21 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_index_of_element_in_int_tab(int n, int *tab, int tab_len)
** This function returns the index of n element in *tab int array argument.
** Returns -1 if the element wasn't found.
*/

int	ft_index_of_element_in_int_tab(int n, int *tab, int tab_len)
{
	int	i;

	i = -1;
	while (++i < tab_len)
	{
		if (tab[i] == n)
			return (i);
	}
	return (-1);
}
