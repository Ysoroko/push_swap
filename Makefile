# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 13:54:31 by ysoroko           #+#    #+#              #
#    Updated: 2021/07/04 15:33:26 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DL_LST			=		dl_lst/ft_dl_lst_add_back.c \
						dl_lst/ft_dl_lst_add_front.c \
						dl_lst/ft_dl_lst_delone_relink.c \
						dl_lst/ft_dl_lst_delone.c \
						dl_lst/ft_dl_lst_first.c \
						dl_lst/ft_dl_lst_insert_element.c \
						dl_lst/ft_dl_lst_last.c \
						dl_lst/ft_dl_lst_new_exit.c \
						dl_lst/ft_dl_lst_size.c \
						dl_lst/ft_dl_lstclear.c \
						dl_lst/ft_dl_lstiter.c \
						dl_lst/ft_dl_lstmap_exit.c \
						dl_lst/ft_dl_lst_swap.c \
						dl_lst/ft_dl_lst_remove_last.c \
						dl_lst/ft_dl_lst_remove_first.c \
						dl_lst/ft_dl_lst_lowest_content.c \
						dl_lst/ft_dl_lst_min_in_top_half.c \
						dl_lst/ft_dl_lst_swap_top_two.c \
						dl_lst/ft_dl_lst_current_index.c \
						dl_lst/ft_dl_lst_max.c \
						dl_lst/ft_dl_lst_min.c \
						dl_lst/ft_dl_lst_next_content.c \
						dl_lst/ft_dl_lst_previous_content.c \
						dl_lst/ft_dl_lst_n_rot_to_reach_elem.c \
						dl_lst/ft_dl_lst_n_rrot_to_reach_elem.c \
						dl_lst/ft_dl_lst_search_elem.c \
						

CONDITIONS		=		conditions/ft_top_two_elems_to_swap.c \
						conditions/ft_stack_a_is_sorted.c \
						conditions/ft_top_and_bottom_to_rotate.c \
						conditions/ft_elem_is_in_next_part.c \
						conditions/ft_number_of_moves_from_the_top.c \
						conditions/ft_number_of_moves_from_the_bottom.c \
						conditions/ft_first_elem_from_next_part_top.c \
						conditions/ft_first_elem_from_next_part_bottom.c \
						conditions/ft_int_elem_is_in_next_part.c \
						conditions/ft_index_of_element_in_int_tab.c \
						conditions/ft_remove_element_from_int_tab.c \

LIBFT_UTILS		=		libft_utils/ft_atol.c \
						libft_utils/ft_element_found_in_int_tab.c \
						libft_utils/ft_isnum.c \
						libft_utils/ft_str_is_number.c \
						libft_utils/ft_write_utils.c \
						libft_utils/ft_atoi.c \
						libft_utils/ft_int_tab_is_sorted.c \
						libft_utils/ft_dl_lst_is_sorted.c \
						libft_utils/ft_strlcmp.c \
						libft_utils/ft_calloc.c \
						libft_utils/ft_bzero.c \
						libft_utils/ft_n_chars_in_int.c \
						libft_utils/ft_putendl_color.c \
						libft_utils/ft_free_int_tab.c \
						libft_utils/ft_initialize_variables_for_algo.c \

INSTRUCTIONS	=		instructions/ft_sa.c \
						instructions/ft_sb.c \
						instructions/ft_ss.c \
						instructions/ft_pa.c \
						instructions/ft_pb.c \
						instructions/ft_ra.c \
						instructions/ft_rb.c \
						instructions/ft_rr.c \
						instructions/ft_rra.c \
						instructions/ft_rrb.c \
						instructions/ft_rrr.c

ALGOS			=		algos/ft_three_or_less_algo.c \
						algos/ft_determine_and_apply_algo.c \
						algos/ft_behind_the_scene_algo.c \
						algos/ft_five_or_less_algo.c \
						algos/ft_hundred_or_less_algo.c \
						algos/ft_general_algo.c \


DEBUG			=		bonus/ft_print_stacks.c

SRC					=	$(DL_LST) \
						$(LIBFT_UTILS) \
						$(INSTRUCTIONS) \
						$(CONDITIONS) \
						main.c

CHECKER				=	bonus/checker.c \
						bonus/main.c

BONUS_SRCS			=	$(DL_LST) \
						$(LIBFT_UTILS) \
						$(INSTRUCTIONS) \
						$(CONDITIONS) \
						$(CHECKER)

OBJS				=	$(SRC:.c=.o)



# Colors
BOLD_PURPLE			=	\033[1;35m

BOLD_CYAN			=	\033[1;36m

BOLD_YELLOW			=	\033[1;33m

NO_COLOR			=	\033[0m

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

EXECUTABLE	=	push_swap

BONUS_EXECUTABLE = checker

LIBRARY	=	push_swap.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(OBJS) $(EXECUTABLE)
		gcc $(FLAGS) $(LIBRARY) -o $(EXECUTABLE)

# Compiles everything with warning flags and runs the executable
run:	
		@gcc $(FLAGS) $(SRC) $(DEBUG) $(ALGOS) -o $(EXECUTABLE) && ./$(EXECUTABLE)

# Compiles everything without warning flags and runs the executable
wrun:
		@gcc $(SRC) $(DEBUG) $(ALGOS) -o $(EXECUTABLE) && ./$(EXECUTABLE)

brun:
		@gcc $(BONUS_SRCS) $(DEBUG) -o $(BONUS_EXECUTABLE) && ./$(BONUS_EXECUTABLE)

# Remove all ".o" files
clean:
		@rm -rf $(OBJS)
		@$(CLEANED)

# Remove all ".o / .a / minishell executable" files
fclean:	clean
		@rm -rf $(NAME)
		@rm -rf $(EXECUTABLE)
		@rm -rf $(BONUS_EXECUTABLE)
		@$(FCLEANED)

re:		fclean all

.PHONY: all clean fclean re run wrun .c.o
