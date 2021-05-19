# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 11:12:03 by ysoroko           #+#    #+#              #
#    Updated: 2021/05/19 13:45:26 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DL_LST		=			dl_lst/ft_dl_lst_add_back.c \
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
						dl_lst/ft_dl_lstmap_exit.c

LIBFT_UTILS	=			libft_utils/ft_atou.c \
						libft_utils/ft_element_found_in_int_tab.c \
						libft_utils/ft_isnum.c \
						libft_utils/ft_str_is_number.c \
						libft_utils/ft_write_utils.c




SRC					=	main.c $(DL_LST)

OBJS				=	$(SRC:.c=.o)

# Colors
BOLD_PURPLE			=	\033[1;35m

BOLD_CYAN			=	\033[1;36m

BOLD_YELLOW			=	\033[1;33m

NO_COLOR			=	\033[0m


NAME		=	minishell.a

FLAGS		=	-Wall -Wextra -Werror

LINK		=	ar rcs

INCLUDE		=	-I include

EXECUTABLE	=	push_swap

PUSH_SWAP_COMPILED = echo "\n↔️🔄 $(BOLD_PURPLE)Executable $(BOLD_CYAN)\"$(EXECUTABLE)\" $(BOLD_PURPLE)created and ready for use!\n$(NO_COLOR)"

CLEANED		=	echo "\n🧼 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧽 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed all the \".a\" files and the \"minishell\" executable \n"						

.c.o:
	@${CC} ${CFLAGS} -I include -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		@gcc $(FLAGS) $(OBJS) -o $(EXECUTABLE)
		@$(PUSH_SWAP)

# Compiles everything with warning flags and runs the executable
run:	$(NAME)
		@./$(EXECUTABLE)

# Compiles everything without warning flags and runs the executable
wrun:	$(OBJS)
		@gcc $(OBJS) -o $(EXECUTABLE) && ./$(EXECUTABLE)

# Remove all ".o" files
clean:
		@rm -rf $(OBJS)
		@cd libft && make clean
		@$(CLEANED)

# Remove all ".o / .a / minishell executable" files
fclean:	clean
		@rm -rf $(NAME)
		@rm -rf $(EXECUTABLE)
		@cd libft && make fclean
		@$(FCLEANED)

re:		fclean all

.PHONY: all clean fclean re run wrun compiling_minishell .c.o minishell.a
