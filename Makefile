# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 13:54:31 by ysoroko           #+#    #+#              #
#    Updated: 2021/05/20 17:16:37 by ysoroko          ###   ########.fr        #
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
						dl_lst/ft_dl_lst_remove_last.c

LIBFT_UTILS		=		libft_utils/ft_atou.c \
						libft_utils/ft_element_found_in_int_tab.c \
						libft_utils/ft_isnum.c \
						libft_utils/ft_str_is_number.c \
						libft_utils/ft_write_utils.c \
						libft_utils/ft_atoi.c \
						libft_utils/ft_int_tab_is_sorted.c \

INSTRUCTIONS	=		instructions/ft_pa_pb.c \
						instructions/ft_sa_sb_ss.c

SRC					=	$(DL_LST) \
						$(LIBFT_UTILS) \
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
		@gcc $(SRC) && ./$(EXECUTABLE)

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
