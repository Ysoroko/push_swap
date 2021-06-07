/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:16:47 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/24 09:23:42 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	if (str[0] == '-')
		i++;
	while (str[i] && ft_isnum(str[i]))
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret);
}
