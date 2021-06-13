/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine_and_apply_algo.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:50:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/06/13 16:01:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_sorted_copy_of_sa(t_dl_lst **stack_a)
{
	t_dl_lst	*sorted_a;
	t_dl_lst	*current;
	int			*ret;
	int			i;

	current = *stack_a;
	i = -1;
	sorted_a = ft_dl_lst_new_exit((*stack_a)->content);
	while (current)
	{
		ft_dl_lst_add_back(&sorted_a, ft_dl_lst_new_exit(current->content));
		current = current->next;
	}
	ft_general_algo(&sorted_a);
	ret = malloc(sizeof(int) * ft_dl_lst_size(*stack_a));
	if (!ret)
		exit(EXIT_FAILURE);
	while (sorted_a)
	{
		ret[++i] = sorted_a->content;
		sorted_a = sorted_a->next;
	}
	ft_dl_lstclear(sorted_a);
	return (ret);
}

void	ft_determine_and_apply_algo(t_dl_lst **stack_a)
{
	int		n_elems;
	int		*sorted_version;

	n_elems = ft_dl_lst_size(*stack_a);
	if (n_elems <= 3)
		ft_three_or_less_algo(stack_a);
	else if (n_elems > 3 && n_elems <= 5)
		ft_general_algo(stack_a);
	else
	{
		sorted_version = ft_sorted_copy_of_sa(stack_a);
		ft_general_algo(stack_a);
	}
	free(sorted_version);
}
