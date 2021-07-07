# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 13:54:31 by ysoroko           #+#    #+#              #
#    Updated: 2021/07/07 12:14:44 by ysoroko          ###   ########.fr        #
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
						libft_utils/ft_n_ints_in_str.c \
						libft_utils/ft_strchr.c \
						libft_utils/ft_split.c \
						libft_utils/ft_free_str_tab.c

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
						$(ALGOS) \
						main.c

OBJS				=	$(SRC:.c=.o)

CHECKER				=	bonus/checker.c \
						bonus/main.c

BONUS_SRCS			=	$(DL_LST) \
						$(LIBFT_UTILS) \
						$(INSTRUCTIONS) \
						$(CONDITIONS) \
						$(CHECKER)

BONUS_OBJS			=	$(BONUS_SRCS:.c=.o)

# Colors
BOLD_PURPLE			=	\033[1;35m

BOLD_CYAN			=	\033[1;36m

BOLD_YELLOW			=	\033[1;33m

NO_COLOR			=	\033[0m

CLEANED		=	echo "\n🧼 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧽 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

PUSH_SWAP_COMPILED = echo "\n📶 $(BOLD_PURPLE)Executable $(BOLD_CYAN)\"$(EXECUTABLE)\" $(BOLD_PURPLE)created and ready for use!\n$(NO_COLOR)"

BONUS_COMPILED = echo "\n✅ $(BOLD_PURPLE)Executable $(BOLD_CYAN)\"$(BONUS_EXECUTABLE)\" $(BOLD_PURPLE)created and ready for use!\n$(NO_COLOR)"

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

EXECUTABLE	=	push_swap

SUBJECT_CHECKER	= checker_Mac

BONUS_EXECUTABLE = checker

LIBRARY	=	push_swap.a

COUNT_OPS = wc -l

THREE = 2 1 0

FIVE = 1 5 2 4 3

HUNDRED =  19   32   53   17   94   31   39   63   71   46   62   83    5   11   14   92   88   90   74   29   22   69   57   73   20   81   23   51   56   48   97   70   58    1   27   85    8   10   37   64   59   76   25   65   75   67   60   99   18   34   98   72   84  100   96   33   78   30    9   55   50    3   86   87   44   52    6   13   45   15   24   21   54   43   68   80   93   36   26   89   79   16   49    2   82    4   40   41   66   61    7   77   38   47   95   91   28   35   12   42

FIVE_HUNDRED = 375  260  256  155   39  100  449  214  129    3  282  383  305  338  355  177  111  310  341  182  163  248   92  348  398   56   91  183  336  357  125  242   16  461  189  340  273  330  204   94  253  473  382  465  154  150   57   55  145   67  459  315  259  411   68  139  394  191  489  447  334  119  445  424  481  156  434  293  209  475  354  497  229   13  141  478  246   46  426  226  219  244   99  286  105   25  268   59    2  135  417    1   10  387  409  484   62   71  101  364   54  476  109  188  284  425  458  108  110  117  106   43  300  431  372   35  423  127  283  130  371  166  443  335   70  220   82   50   18  427  454   90  251  187  362  308   45  322  287  373  312  180  317  170  487  479   36  378  363  222  377   14  224    8  175   98  264  485  325   74  252  153  408  271  247   86  196   48  395   61  321  349  450  430  151   83   42  234   24  490  272  302  499  316  133  276   15   65  303  342  416  456  237  258  328  239  245   27  186  384  181  376  227   81  319  116  444  474  406  480  249  194  228  405  304  415  140  391   49  320   89  389  132  275  270  269  280  491  361  263  369  460  399  165  238  309  254   69   72  436   84  390   52  403  374  176  171  468  494   75  339  492  397  104   12  324  112   53   29  463    7  495  241  332   97  144  380   78  301  418   63    4   93  297  343  323  365  200  350   41  192  113  121   40   60  358  233  483   79   51  211   20  218  462  267   30  428  212  360  114  152  262  307  184  306  467  179  419  500  257  441   28  162  331  496  420  298   95  178  167  367  147  289  486   34  142  400  131  337  407  208  240  288   32   38   47  137  168  225  386   33  477  345  347  102  230  433  143  455  265  185  210   11  164  161  207  261  174  422   96  290  198  202  413  158  379  429   77   37  172  464  199   17  255   87  299  159  488   19  107  351  471  243   66   26   44  451  221  402  146  217   64  437  314  279  266  296  452  453  311  195  393  385  123  432  333  124  448  438  396  235  103  359  368  472  466  173  493   80  236  329  118  440  115   31  190  285  327  231  344  291   23  346  169  250  439  122  388  410   22  412  215  148  295  274  223  206  446  149   58  421  356   88  157  134  205  392  435  213  203  318    6  281  277  470  292  482   76   73  498  216  352  120  366  294  126  414  381  232  197  326    9  442  201  193  136  353  160  401  313    5  138  128  278  457  370   21  469  404   85

NAME = push_swap

.c.o:
	@gcc ${FLAGS} -I include -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		@gcc $(FLAGS) $(OBJS) -o $(EXECUTABLE)
		@$(PUSH_SWAP_COMPILED)

bonus: $(BONUS_OBJS)
		@gcc $(FLAGS) $(BONUS_OBJS) -o $(BONUS_EXECUTABLE)
		@$(BONUS_COMPILED)

# --------------------------------TESTS-----------------------------

# THREE ELEMENTS: 2 1 0
test_three_count:
		./$(EXECUTABLE) $(THREE) | $(COUNT_OPS)

test_three_checker:
		./$(EXECUTABLE) $(THREE) | ./$(SUBJECT_CHECKER) $(THREE)
# ------------------------

# FIVE ELEMENTS: 1 5 2 4 3
test_five_count:
		./$(EXECUTABLE) $(FIVE) | $(COUNT_OPS)

test_five_checker:
		./$(EXECUTABLE) $(FIVE) | ./$(SUBJECT_CHECKER) $(FIVE)
# ------------------------

# 100 ELEMENTS: 19   32   53   17   94   31   39   63   71   46   62   83    5   11   14   92   88   90   74   29   22   69   57   73   20   81   23   51   56   48   97   70   58    1   27   85    8   10   37   64   59   76   25   65   75   67   60   99   18   34   98   72   84  100   96   33   78   30    9   55   50    3   86   87   44   52    6   13   45   15   24   21   54   43   68   80   93   36   26   89   79   16   49    2   82    4   40   41   66   61    7   77   38   47   95   91   28   35   12   42
test_hundred_count:
		./$(EXECUTABLE) $(HUNDRED) | $(COUNT_OPS)
test_hundred_checker:
		./$(EXECUTABLE) $(HUNDRED) | ./$(SUBJECT_CHECKER) $(HUNDRED)
# ------------------------

# 500 ELEMENTS: 375  260  256  155   39  100  449  214  129    3  282  383  305  338  355  177  111  310  341  182  163  248   92  348  398   56   91  183  336  357  125  242   16  461  189  340  273  330  204   94  253  473  382  465  154  150   57   55  145   67  459  315  259  411   68  139  394  191  489  447  334  119  445  424  481  156  434  293  209  475  354  497  229   13  141  478  246   46  426  226  219  244   99  286  105   25  268   59    2  135  417    1   10  387  409  484   62   71  101  364   54  476  109  188  284  425  458  108  110  117  106   43  300  431  372   35  423  127  283  130  371  166  443  335   70  220   82   50   18  427  454   90  251  187  362  308   45  322  287  373  312  180  317  170  487  479   36  378  363  222  377   14  224    8  175   98  264  485  325   74  252  153  408  271  247   86  196   48  395   61  321  349  450  430  151   83   42  234   24  490  272  302  499  316  133  276   15   65  303  342  416  456  237  258  328  239  245   27  186  384  181  376  227   81  319  116  444  474  406  480  249  194  228  405  304  415  140  391   49  320   89  389  132  275  270  269  280  491  361  263  369  460  399  165  238  309  254   69   72  436   84  390   52  403  374  176  171  468  494   75  339  492  397  104   12  324  112   53   29  463    7  495  241  332   97  144  380   78  301  418   63    4   93  297  343  323  365  200  350   41  192  113  121   40   60  358  233  483   79   51  211   20  218  462  267   30  428  212  360  114  152  262  307  184  306  467  179  419  500  257  441   28  162  331  496  420  298   95  178  167  367  147  289  486   34  142  400  131  337  407  208  240  288   32   38   47  137  168  225  386   33  477  345  347  102  230  433  143  455  265  185  210   11  164  161  207  261  174  422   96  290  198  202  413  158  379  429   77   37  172  464  199   17  255   87  299  159  488   19  107  351  471  243   66   26   44  451  221  402  146  217   64  437  314  279  266  296  452  453  311  195  393  385  123  432  333  124  448  438  396  235  103  359  368  472  466  173  493   80  236  329  118  440  115   31  190  285  327  231  344  291   23  346  169  250  439  122  388  410   22  412  215  148  295  274  223  206  446  149   58  421  356   88  157  134  205  392  435  213  203  318    6  281  277  470  292  482   76   73  498  216  352  120  366  294  126  414  381  232  197  326    9  442  201  193  136  353  160  401  313    5  138  128  278  457  370   21  469  404   85

test_five_hundred_count:
		./$(EXECUTABLE) $(FIVE_HUNDRED) | $(COUNT_OPS)
test_five_hundred_checker:
		./$(EXECUTABLE) $(FIVE_HUNDRED) | ./$(SUBJECT_CHECKER) $(FIVE_HUNDRED)

# ------------------------------------------------------------------

# Remove all ".o" files
clean:
		@rm -rf $(OBJS) $(BONUS_OBJS)
		@$(CLEANED)

# Remove all ".o / .a / minishell executable" files
fclean:	clean
		@rm -rf $(EXECUTABLE)
		@rm -rf $(BONUS_EXECUTABLE)
		@$(FCLEANED)

re:		fclean all

.PHONY: all clean fclean re run wrun brun bonus