# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 11:12:03 by ysoroko           #+#    #+#              #
#    Updated: 2021/05/19 10:29:29 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INPUT_PARSING		=	input_parsing/ft_input_parsing.c \
						input_parsing/ft_extract_next_command.c \
						input_parsing/ft_apply_quotes_and_env_vars.c \
						input_parsing/utils/ft_parsing_utils.c \
						input_parsing/utils/ft_quoted_copy.c \
						input_parsing/utils/ft_env_vars_utils.c

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

# Termcap
# Linking command required to be able to use termcap commands
# Without it, some termcap functions are not recognized despite the #include
TERMCAP		=	-ltermcap

LIBFT		=	cd libft && make bonus

NAME		=	minishell.a

FLAGS		=	-Wall -Wextra -Werror

LINK		=	ar rcs

INCLUDE		=	-I include

EXECUTABLE	=	minishell

MINISHELL_COMPILED = echo "\n🐚 $(BOLD_PURPLE)Executable $(BOLD_CYAN)\"$(EXECUTABLE)\" $(BOLD_PURPLE)created and ready for use!\n$(NO_COLOR)"

CLEANED		=	echo "\n🧼 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧽 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed all the \".a\" files and the \"minishell\" executable \n"						

.c.o:
	@${CC} ${CFLAGS} -I include -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		@$(LIBFT)
		@$(LINK) $(NAME) $(OBJS)
		@gcc $(FLAGS) $(LIBRARIES) $(TERMCAP) -o $(EXECUTABLE)
		@$(MINISHELL_COMPILED)

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
