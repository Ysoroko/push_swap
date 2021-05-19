# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 11:12:03 by ysoroko           #+#    #+#              #
#    Updated: 2021/05/19 10:50:33 by ysoroko          ###   ########.fr        #
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
						dl_lst/ft_dl_lstmap_exit.c \





						

EXECUTE				=	execute/ft_execute.c \
						execute/ft_check_command_for_errors.c

UTILS				=	utils/signal/ft_signal_handler.c

FUNCTIONS			=	functions/ft_echo.c

SRC					=	main.c $(INPUT_PARSING) $(EXECUTE) $(UTILS)

LIBRARIES			=	libft/libft.a \
						minishell.a

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
		@$(LINK) $(NAME) $(OBJS)
		@gcc $(FLAGS) $(LIBRARIES) $(TERMCAP) -o $(EXECUTABLE)
		@$(PUSH_SWAP)

# Compiles everything with warning flags and runs the executable
run:	$(NAME)
		@./$(EXECUTABLE)

# Compiles everything without warning flags and runs the executable
wrun:	$(NAME)
		@gcc $(LIBRARIES) $(TERMCAP) -o $(EXECUTABLE) && ./$(EXECUTABLE)

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
