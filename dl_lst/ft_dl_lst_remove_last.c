/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_remove_last.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:13:55 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/20 17:16:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_dl_lst_remove_last(t_dl_lst *dl_lst)
{
	t_dl_lst	*last;

	last = ft_dl_lst_last(dl_lst);
	free(last);
	last = 0;
}
