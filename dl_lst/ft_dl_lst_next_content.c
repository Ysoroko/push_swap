/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_next_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:53:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/04 13:13:22 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	ft_dl_lst_next_content(t_dl_lst *dl_lst, int new_content)
** This function will find which content in dl_lst
** should be next after new_content
** Returns the content's int value. If there is no next element or dl_lst is 0,
** returns the value of new_content
*/

// What is the "next" element?
// Example: we try to insert 2 in stack_b: [0 -2 -3 -4 -5 -6 -7 1]
// 2 needs to be inserted when 1 is on top, so next element is 1
// let's say we put 1 on top by using rb:
// stack_b: [1 0 -2 -3 -4 -5 -6 -7]
// 1 needs to be less than 2 and the next element (dl_lst_last or current->prev)


// 2nd example: We try to insert -8 in stack_b: [0 -2 -3 -4 -5 -6 -7 1]
// Next element is then -7

// 3rd example:
// im putting [3] in stack_b: [4 2 1 0 -1 -2 -4 -6]
// next is 2: 2 < 3 and 4 > 3

int	ft_dl_lst_next_content(t_dl_lst *dl_lst, int new_content)
{
	t_dl_lst	*current;
	int			next;
	int			current_content;

	if (!dl_lst)
		return (new_content);
	current = dl_lst;
	next = dl_lst->content;
	while (current)
	{
		current_content = current->content;
		if (current != dl_lst)
		{
			if (current_content < new_content &&
				current->previous->content > new_content)
				{
					next = current_content;
				}
			//else if (current->next && current_content > new_content &&
			//		current->next->content < new_content)
			//	{
			//		next = current_content;
			//	}
		}
		else 
		{
			//-1 < 2 ok + 1 > 2
			if (dl_lst->content < new_content &&
				ft_dl_lst_last(dl_lst)->content > next)
			{
				printf("last content: [%d]\n", ft_dl_lst_last(dl_lst)->content);
				next = dl_lst->content;
			}
		}
		current = current->next;
	}
	return (next);
}
