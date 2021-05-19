/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:16:47 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/19 11:39:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

unsigned int	ft_atou(char *str)
{
	int				i;
	unsigned int	ret;

	i = -1;
	ret = 0;
	while (str[i] && ft_isnum(str[i]))
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret);
}
