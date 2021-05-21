/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:27:34 by ysoroko           #+#    #+#             */
/*   Updated: 2021/05/21 11:06:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** LIBFT functions
*/

unsigned int	ft_atou(char *str);
int				ft_str_is_number(char *str);
int				ft_isnum(char c);
int				ft_element_found_in_int_tab(int n, int *tab, int tab_size);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putendl(char *s);
int				ft_atoi(char *str);
int				ft_int_tab_is_sorted(int *tab, int tab_len, int low_to_high);

/*
** Instructions
*/

void			ft_sa_sb_ss(t_dl_lst *stack_a, t_dl_lst *stack_b);
void			ft_pa_pb(t_dl_lst *stack_to_move_from, t_dl_lst **stack_to_move_to);



/*
** DL_LST functions
*/

typedef struct s_dl_lst
{
	int				content;
	struct s_dl_lst	*next;
	struct s_dl_lst	*previous;
}				t_dl_lst;

t_dl_lst	*ft_dl_lst_new_exit(int content);
void		ft_dl_lst_add_front(t_dl_lst *add_before,
				t_dl_lst *new_member);
int			ft_dl_lst_size(t_dl_lst *first);
t_dl_lst	*ft_dl_lst_last(t_dl_lst *first);
t_dl_lst	*ft_dl_lst_first(t_dl_lst *last);
void		ft_dl_lst_insert_element(t_dl_lst *new, t_dl_lst *after,
				t_dl_lst *bef);
void		ft_dl_lst_add_back(t_dl_lst *add_after,
				t_dl_lst *new_member);
void		ft_dl_lstdelone(t_dl_lst *to_delete);
void		ft_dl_lstdelone_relink(t_dl_lst *to_delete);
void		ft_dl_lstclear(t_dl_lst *lst);
void		ft_dl_lstiter(t_dl_lst *lst, void (*f)(int));
t_dl_lst	*ft_dl_lstmap_exit(t_dl_lst *l, int(*f)(int));
void		ft_dl_lst_swap(t_dl_lst *element_1, t_dl_lst *element_2);
void		ft_dl_lst_remove_last(t_dl_lst *dl_lst);



#endif