/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_search_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:27:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/03 15:41:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_search_elem(t_dl_lst *where_to_search, int elem)
** This algo will search for element "elem" in "where to search" dl_lst
** and return 1 if the element is present in "where to search" or
** return 0 if it's not in there
*/

int	ft_dl_lst_search_elem(t_dl_lst *where_to_search, int elem)
{
	t_dl_lst	*current;

	if (!where_to_search)
		return (0);
	current = where_to_search;
	while (current)
	{
		if (current->content == elem)
			return (1);
		current = current->next;
	}
	return (0);
}
