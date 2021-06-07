/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:42:00 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/07 13:22:39 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ret;

	total_size = size * count;
	ret = malloc(total_size);
	if (ret == 0)
	{
		return (0);
	}
	ft_bzero(ret, total_size);
	return (ret);
}
