/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_element_from_int_tab.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:02:24 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/03 15:20:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_remove_element_from_int_tab(int elem, int **n_tab, int tab_len)
** This function will replace *n_tab int array with a copy of it but with
** elem argument removed from it. 
** Will also change *tab_len value (decrement it by 1)
*/

void	ft_remove_element_from_int_tab(int elem, int **n_tab, int *tab_len)
{
	int	i;
	int	j;
	int	*new_tab;

	i = 0;
	while (i < *tab_len && (*n_tab)[i] != elem)
		i++;
	new_tab = malloc(sizeof(int) * (*tab_len - 1));
	if (!new_tab)
		exit(EXIT_FAILURE);
	j = -1;
	while (++j < *tab_len)
	{
		if (j != i)
			new_tab[j] = (*n_tab)[j];
	}
	if (*tab_len > 0)
		(*tab_len)--;
	*n_tab = new_tab;
}
