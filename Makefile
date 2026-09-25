CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

SRCS_DIR	= main
UTILS_DIR	= $(SRCS_DIR)/utils
OP_DIR		= $(SRCS_DIR)/operations
ALG_DIR		= $(SRCS_DIR)/sorting
SRCS		= $(UTILS_DIR)/bench_utils_1.c \
			  $(SRCS_DIR)/main.c \
			  $(UTILS_DIR)/main_utils_3.c \
			  $(OP_DIR)/push.c \
			  $(OP_DIR)/swap.c \
			  $(ALG_DIR)/complex_sort.c \
			  $(UTILS_DIR)/main_utils_1.c \
			  $(UTILS_DIR)/main_utils_4.c \
			  $(OP_DIR)/rev_rot.c \
			  $(UTILS_DIR)/helper_utils_1.c \
			  $(UTILS_DIR)/main_utils_2.c \
			  $(OP_DIR)/rot.c \
			  $(ALG_DIR)/simple_sort.c \
			  $(ALG_DIR)/medium_sort.c

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a
INCLUDES	= -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)/includes
OBJS		= $(SRCS:.c=.o)
NAME		= push_swap

BONUS		= checker
BONUS_DIR	= bonus
BONUS_SRCS	= $(BONUS_DIR)/checker_utils_2.c \
			$(BONUS_DIR)/helper_utils_1.c \
			$(BONUS_DIR)/rot.c \
			$(BONUS_DIR)/checker.c \
			$(BONUS_DIR)/checker_utils_3.c \
			$(BONUS_DIR)/push.c \
			$(BONUS_DIR)/swap.c \
			$(BONUS_DIR)/checker_utils_1.c \
			$(BONUS_DIR)/get_next_line.c \
			$(BONUS_DIR)/rev_rot.c

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INCLUDES	= -I $(BONUS_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)/includes

NAME		= push_swap

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

both: all bonus

$(OBJS): includes/push_swap.h

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

$(BONUS_OBJS): $(BONUS_DIR)/bonus.h

$(BONUS): $(LIBFT) $(PRINTF) $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(LIBFT) $(PRINTF) -o $(BONUS)

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean:	clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:	fclean all

bonus: $(BONUS)

b_clean:
	$(RM) $(BONUS_OBJS)
	make -C libft clean
	make -C ft_printf clean

b_fclean: b_clean
	$(RM) $(BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

b_re: b_fclean bonus

clean_all: clean b_clean

fclean_all: fclean b_fclean

re_all: re b_re

.PHONY: all clean fclean re bonus b_clean b_fclean b_re both clean_all fclean_all re_all
