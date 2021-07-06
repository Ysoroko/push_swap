/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine_and_apply_algo.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:50:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 15:12:04 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** int	*ft_sorted_copy_of_sa(t_dl_lst **stack_a)
** This function will create a copy of stack_a, sort it (unefficiently)
** and then it will return the sorted elements as an int tab
*/

int	*ft_sorted_copy_of_sa(t_dl_lst **stack_a)
{
	t_dl_lst	*sorted_a;
	t_dl_lst	*current;
	int			*ret;
	int			i;

	i = -1;
	sorted_a = ft_dl_lst_new_exit((*stack_a)->content);
	current = (*stack_a)->next;
	while (current)
	{
		ft_dl_lst_add_back(&sorted_a, ft_dl_lst_new_exit(current->content));
		current = current->next;
	}
	ft_behind_the_scene_algo(&sorted_a);
	ret = malloc(sizeof(int) * ft_dl_lst_size(*stack_a));
	if (!ret)
		exit(EXIT_FAILURE);
	current = sorted_a;
	while (current)
	{
		ret[++i] = current->content;
		current = current->next;
	}
	ft_dl_lstclear(sorted_a);
	return (ret);
}

/*
** void	ft_determine_and_apply_algo(t_dl_lst **stack_a)
** This functions receives stack_a as it is (as main arguments)
** It will check the number of elements in the stack and based on it
** it will decide which algorythm to perform and perform it
*/

void	ft_determine_and_apply_algo(t_dl_lst **stack_a)
{
	int		n_elems;
	int		*sorted_version;

	n_elems = ft_dl_lst_size(*stack_a);
	sorted_version = ft_sorted_copy_of_sa(stack_a);
	if (n_elems <= 3)
		ft_three_or_less_algo(stack_a);
	else if (n_elems > 3 && n_elems <= 5)
		ft_five_or_less_algo(stack_a);
	else if (n_elems > 5 && n_elems <= 200)
		ft_hundred_or_less_algo(stack_a, sorted_version, n_elems);
	else
		ft_general_algo(stack_a, sorted_version, n_elems);
	free(sorted_version);
}
