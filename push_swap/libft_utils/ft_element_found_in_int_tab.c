/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_found_in_int_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 10:38:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_element_found_in_int_tab(int n, int *tab, int tab_size)
{
	int	i;

	i = -1;
	if (!tab)
		return (0);
	while (++i < tab_size)
	{
		if (tab[i] == n)
			return (1);
	}
	return (0);
}
