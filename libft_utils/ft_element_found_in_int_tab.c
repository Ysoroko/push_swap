/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_found_in_int_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 14:53:17 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_element_found_in_int_tab(int n, int *tab, int tab_size)
{
	int	i;

	i = -1;
	while (++i < tab_size)
	{
		if (tab[i] == n)
			return (1);
	}
	return (0);
}
