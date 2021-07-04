/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:58:55 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/04 15:00:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_free_int_tab(int **tab, int to_return)
** This function will free the **tab argument and return to_return argument
*/

int	ft_free_int_tab(int **tab, int to_return)
{
	if (!tab)
		return (to_return);
	free(*tab);
	return (to_return);
}
