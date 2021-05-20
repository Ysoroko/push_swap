/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:17:28 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 15:19:31 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This is a modified version of ft_atoi
** We already know that the string is composed only of digits and there are no
** overflows when calling this function so no need to check these
** Converts str string argument composed of digits to an int
*/

int	ft_atoi(char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (str[++i])
		ret = ret * 10 + (str[i] - '0');
	return (ret);
}
