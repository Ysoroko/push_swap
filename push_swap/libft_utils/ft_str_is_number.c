/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:15:49 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 14:41:12 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_str_is_number(char *str)
** This function checks if the string is composed only of digit characters
** Returns 1 if yes, 0 if a character other than "-0123456789" is found inside
** or the string is solely composed of a loose '-' symbol
*/

int	ft_str_is_number(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
	{
		if (!str[1])
			return (0);
		i++;
	}
	while (str[++i])
	{
		if (!(ft_isnum(str[i])))
			return (0);
	}
	return (1);
}
