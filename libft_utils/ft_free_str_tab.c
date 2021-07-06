/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:11:31 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 12:12:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**
*/

int	ft_free_str_tab(char **str_tab, int to_return)
{
	int	i;

	i = -1;
	if (!str_tab)
		return (to_return);
	while (str_tab[++i])
		free(str_tab[i]);
	free(str_tab);
	return (to_return);
}
