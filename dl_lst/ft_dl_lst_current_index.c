/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_current_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:51:19 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/09 16:05:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_current_index(t_dl_lst *dl_lst, t_dl_lst *element_to_find)
** This function will return the index of the element_to_find in dl_lst
** argument. We consider dl_lst being the first member of dl_lst list.
** The count starts at 1 (1st element = 1) and the function returns -1
** if the element wasn't found or dl_lst argument is NULL
*/

int	ft_dl_lst_current_index(t_dl_lst *dl_lst, t_dl_lst *element_to_find)
{
	int			count;
	t_dl_lst	*counter;

	if (!dl_lst || !element_to_find)
		return (-1);
	count = 1;
	counter = dl_lst;
	while (counter && counter != element_to_find)
	{
		counter = counter->next;
		count++;
	}
	if (!counter && element_to_find)
		return (-1);
	return (count);
}
