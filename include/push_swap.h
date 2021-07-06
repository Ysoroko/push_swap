/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:27:34 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/06 14:16:00 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

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
void		ft_dl_lst_add_front(t_dl_lst **add_before,
				t_dl_lst *new_member);
int			ft_dl_lst_size(t_dl_lst *first);
t_dl_lst	*ft_dl_lst_last(t_dl_lst *first);
t_dl_lst	*ft_dl_lst_first(t_dl_lst *last);
void		ft_dl_lst_insert_element(t_dl_lst *to_insert, t_dl_lst *after,
				t_dl_lst *bef);
void		ft_dl_lst_add_back(t_dl_lst **add_after,
				t_dl_lst *new_member);
void		ft_dl_lstdelone(t_dl_lst *to_delete);
void		ft_dl_lstdelone_relink(t_dl_lst *to_delete);
void		ft_dl_lstclear(t_dl_lst *lst);
void		ft_dl_lstiter(t_dl_lst *lst, void (*f)(int));
t_dl_lst	*ft_dl_lstmap_exit(t_dl_lst *l, int(*f)(int));
void		ft_dl_lst_swap(t_dl_lst *element_1, t_dl_lst *element_2);
void		ft_dl_lst_remove_last(t_dl_lst **dl_lst);
void		ft_dl_lst_remove_first(t_dl_lst **dl_lst);
int			ft_dl_lst_lowest_content(t_dl_lst *dl_lst);
int			ft_dl_lst_min_in_top_half(t_dl_lst *dl_lst);
void		ft_dl_lst_swap_top_two(t_dl_lst **dl_lst);
int			ft_dl_lst_current_index(t_dl_lst *dl_lst,
				t_dl_lst *element_to_find);
int			ft_dl_lst_max(t_dl_lst *dl_lst);
int			ft_dl_lst_min(t_dl_lst *dl_lst);
int			ft_dl_lst_next_content(t_dl_lst *dl_lst, int new_content);
int			ft_dl_lst_previous_content(t_dl_lst *dl_lst, int new_content);
int			ft_dl_lst_n_rot_to_reach_elem(t_dl_lst *dl_lst, int elem);
int			ft_dl_lst_n_rrot_to_reach_elem(t_dl_lst *dl_lst, int elem);
int			ft_dl_lst_search_elem(t_dl_lst *where_to_search, int elem);

/*
** LIBFT functions
*/

long		ft_atol(char *str);
int			ft_str_is_number(char *str);
int			ft_isnum(char c);
int			ft_element_found_in_int_tab(int n, int *tab, int tab_size);
void		ft_putchar(char c, int fd);
void		ft_putstr(char *str, int fd);
void		ft_putendl(char *s, int fd);
int			ft_atoi(char *str);
int			ft_int_tab_is_sorted(int *tab, int tab_len, int low_to_high);
int			ft_dl_lst_is_sorted(t_dl_lst *lst, int ascending_order);
void		*ft_calloc(size_t count, size_t size);
int			ft_strlcmp(char *s1, char *s2);
void		ft_bzero(void *str, size_t n);
int			ft_n_chars_in_int(int n);
int			ft_putendl_color(char *str, char *color, int to_return, int fd);
int			ft_free_int_tab(int **tab, int to_return);
void		ft_initialize_variables_for_algo(int *a, t_dl_lst **b, int *c);
int			ft_n_ints_in_str(char *str);
int			ft_strchr(char *str, char c);
char		**ft_split(char const *str, char charset);
int			ft_free_str_tab(char **str_tab, int to_return);

/*
** Conditions
*/

int			ft_top_two_elems_to_swap(t_dl_lst *stack);
int			ft_stack_a_is_sorted(t_dl_lst *stack_a);
int			ft_top_and_bottom_to_rotate(t_dl_lst *stack_a);
int			ft_elem_is_in_next_part(t_dl_lst *stack_a, int *next_part,
				int p_size);
int			ft_number_of_moves_from_the_top(t_dl_lst *stack_a, int until_elem);
int			ft_number_of_moves_from_the_bottom(t_dl_lst *stack_a,
				int until_elem);
int			ft_first_elem_from_next_part_top(t_dl_lst *stack_a,
				t_dl_lst *stack_b, int *part, int p_len);
int			ft_first_elem_from_next_prt_bottom(t_dl_lst *stack_a,
				t_dl_lst *stack_b, int *part, int p_ln);
int			ft_int_elem_is_in_next_part(int n, int *next_part, int p_size);
int			ft_index_of_element_in_int_tab(int n, int *tab, int tab_len);
void		ft_remove_element_from_int_tab(int elem, int **n_tab, int *tab_ln);

/*
** Instructions
*/

int			ft_sa(t_dl_lst **stack_a, int write_sa);
int			ft_sb(t_dl_lst **stack_b, int write_sb);
int			ft_ss(t_dl_lst **stack_a, t_dl_lst **stack_b, int write_ss);
int			ft_pa(t_dl_lst **stack_b, t_dl_lst **stack_a, int write_pa);
int			ft_pb(t_dl_lst **stack_a, t_dl_lst **stack_b, int write_pb);
int			ft_ra(t_dl_lst **stack_a, int write_ra);
int			ft_rb(t_dl_lst **stack_b, int write_rb);
int			ft_rr(t_dl_lst **stack_a, t_dl_lst **stack_b, int write_rr);
int			ft_rra(t_dl_lst **stack_a, int write_rra);
int			ft_rrb(t_dl_lst **stack_b, int write_rrb);
int			ft_rrr(t_dl_lst **stack_a, t_dl_lst **stack_b, int write_rrr);

/*
** PUSH_SWAP
*/

void		ft_determine_and_apply_algo(t_dl_lst **stack_a);
void		ft_three_or_less_algo(t_dl_lst **stack_a);
void		ft_five_or_less_algo(t_dl_lst **stack_a);
void		ft_hundred_or_less_algo(t_dl_lst **stack_a, int *sorted_a,
				int n_elems);
void		ft_behind_the_scene_algo(t_dl_lst **stack_a);
void		ft_general_algo(t_dl_lst **s_a, int *sort_a, int l);

/*
** CHECKER
*/

int			checker(t_dl_lst **stack_a);

/*
** DEBUG
*/

void		ft_print_stacks(t_dl_lst *stack_a, t_dl_lst *stack_b);
void		ft_print_next_part(int *part, int len);

/*
** CONSTANTS
*/

# define ALLOWED_CHARS_SINGLE_ARGV " -0123456789"
# define N_PARTS_UNDER_HUNDRED 6
# define N_PARTS_GENERAL 11
# define DISPLAY_INSTRUCTIONS 1
# define STDOUT 1
# define STDERR 2

/*
** COLORS
*/

# define COLOR_RESET   "\x1b[0m"

# define BOLD_RED "\033[1m\033[31m"
# define BOLD_GREEN "\033[1m\033[32m"
# define BOLD_YELLOW "\033[1m\033[33m"
# define BOLD_BLUE "\033[1m\033[34m"
# define BOLD_MAGENTA "\033[1m\033[35m"
# define BOLD_CYAN "\033[1m\033[36m"
# define BOLD_WHITE "\033[1m\033[37m"

# define INPUT_SIZE 256

#endif