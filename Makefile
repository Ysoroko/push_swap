# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 13:54:31 by ysoroko           #+#    #+#              #
#    Updated: 2021/06/04 13:53:44 by ysoroko          ###   ########.fr        #
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
						dl_lst/ft_dl_lst_swap_top_two.c

CONDITIONS		=		conditions/ft_top_two_elems_to_swap.c \
						conditions/ft_stack_a_is_sorted.c

LIBFT_UTILS		=		libft_utils/ft_atol.c \
						libft_utils/ft_element_found_in_int_tab.c \
						libft_utils/ft_isnum.c \
						libft_utils/ft_str_is_number.c \
						libft_utils/ft_write_utils.c \
						libft_utils/ft_atoi.c \
						libft_utils/ft_int_tab_is_sorted.c \
						libft_utils/ft_dl_lst_is_sorted.c

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
						

SRC					=	$(DL_LST) \
						$(LIBFT_UTILS) \
						$(INSTRUCTIONS) \
						$(CONDITIONS) \
						main.c

OBJS				=	$(SRC:.c=.o)

# Colors
BOLD_PURPLE			=	\033[1;35m

BOLD_CYAN			=	\033[1;36m

BOLD_YELLOW			=	\033[1;33m

NO_COLOR			=	\033[0m

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

EXECUTABLE	=	push_swap

LIBRARY	=	push_swap.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(OBJS) $(EXECUTABLE)
		gcc $(FLAGS) $(LIBRARY) -o $(EXECUTABLE)

# Compiles everything with warning flags and runs the executable
run:	
		@gcc $(FLAGS) $(SRC) -o $(EXECUTABLE) && ./$(EXECUTABLE)

# Compiles everything without warning flags and runs the executable
wrun:
		@gcc $(SRC) -o $(EXECUTABLE) && ./$(EXECUTABLE) bonjour

# Remove all ".o" files
clean:
		@rm -rf $(OBJS)
		@$(CLEANED)

# Remove all ".o / .a / minishell executable" files
fclean:	clean
		@rm -rf $(NAME)
		@rm -rf $(EXECUTABLE)
		@$(FCLEANED)

re:		fclean all

.PHONY: all clean fclean re run wrun .c.o
