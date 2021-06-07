# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 12:04:54 by ysoroko           #+#    #+#              #
#    Updated: 2021/06/07 14:17:41 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP		=		../push_swap/


DL_LST			=		$(PUSH_SWAP)dl_lst/ft_dl_lst_add_back.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_add_front.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_delone_relink.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_delone.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_first.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_insert_element.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_last.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_new_exit.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_size.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lstclear.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lstiter.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lstmap_exit.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_swap.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_remove_last.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_remove_first.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_lowest_content.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_min_in_top_half.c \
						$(PUSH_SWAP)dl_lst/ft_dl_lst_swap_top_two.c

CONDITIONS		=		$(PUSH_SWAP)conditions/ft_top_two_elems_to_swap.c \
						$(PUSH_SWAP)conditions/ft_stack_a_is_sorted.c

LIBFT_UTILS		=		$(PUSH_SWAP)libft_utils/ft_atol.c \
						$(PUSH_SWAP)libft_utils/ft_element_found_in_int_tab.c \
						$(PUSH_SWAP)libft_utils/ft_isnum.c \
						$(PUSH_SWAP)libft_utils/ft_str_is_number.c \
						$(PUSH_SWAP)libft_utils/ft_write_utils.c \
						$(PUSH_SWAP)libft_utils/ft_atoi.c \
						$(PUSH_SWAP)libft_utils/ft_int_tab_is_sorted.c \
						$(PUSH_SWAP)libft_utils/ft_dl_lst_is_sorted.c \
						$(PUSH_SWAP)libft_utils/ft_strlcmp.c \
						$(PUSH_SWAP)libft_utils/ft_calloc.c \
						$(PUSH_SWAP)libft_utils/ft_bzero.c

INSTRUCTIONS	=		$(PUSH_SWAP)instructions/ft_sa.c \
						$(PUSH_SWAP)instructions/ft_sb.c \
						$(PUSH_SWAP)instructions/ft_ss.c \
						$(PUSH_SWAP)instructions/ft_pa.c \
						$(PUSH_SWAP)instructions/ft_pb.c \
						$(PUSH_SWAP)instructions/ft_ra.c \
						$(PUSH_SWAP)instructions/ft_rb.c \
						$(PUSH_SWAP)instructions/ft_rr.c \
						$(PUSH_SWAP)instructions/ft_rra.c \
						$(PUSH_SWAP)instructions/ft_rrb.c \
						$(PUSH_SWAP)instructions/ft_rrr.c
						

SRC					=	$(DL_LST) \
						$(LIBFT_UTILS) \
						$(INSTRUCTIONS) \
						$(CONDITIONS) \
						checker.c \
						main.c

OBJS				=	$(SRC:.c=.o)

# Colors
BOLD_PURPLE			=	\033[1;35m

BOLD_CYAN			=	\033[1;36m

BOLD_YELLOW			=	\033[1;33m

NO_COLOR			=	\033[0m

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

EXECUTABLE	=	checker

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