/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_ints_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:20:28 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 14:12:35 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_n_ints_in_str(char *str)
** Returns the number of separate integers represented with digits in str,
** separated by anything but a digit
*/

int	ft_n_ints_in_str(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && !ft_isnum(str[i]))
			i++;
		if (ft_isnum(str[i]))
			count++;
		while (str[i] && ft_isnum(str[i]))
			i++;
	}
	return (count);
}
