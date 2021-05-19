/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:27:34 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/19 10:51:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>

/*
** DL_LST functions
*/

typedef struct s_dl_lst
{
	void			*content;
	struct s_dl_lst	*next;
	struct s_dl_lst	*previous;
}				t_dl_lst;

t_dl_lst	*ft_dl_lst_new_exit(void *content);
void		ft_dl_lst_add_front(t_dl_lst *add_before,
				t_dl_lst *new_member);
int			ft_dl_lst_size(t_dl_lst *first);
t_dl_lst	*ft_dl_lst_last(t_dl_lst *first);
t_dl_lst	*ft_dl_lst_first(t_dl_lst *last);
void		ft_dl_lst_insert_element(t_dl_lst *to_insert,
				t_dl_lst *after_this);
void		ft_dl_lst_add_back(t_dl_lst *add_after,
				t_dl_lst *new_member);
void		ft_dl_lstdelone(t_dl_lst *to_delete, void (*del)(void*));
void		ft_dl_lstdelone_relink(t_dl_lst *to_delete,
				void (*del)(void*));
void		ft_dl_lstclear(t_dl_lst *lst, void (*del)(void*));
void		ft_dl_lstiter(t_dl_lst *lst, void (*f)(void *));
t_dl_lst	*ft_dl_lstmap_exit(t_dl_lst *l, void *(*f)(void *),
				void (*del)(void *));


#endif