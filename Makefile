CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f

SRCS_DIR	= main
SRCS		= $(SRCS_DIR)/bench_utils_1.c \
			  $(SRCS_DIR)/main.c \
			  $(SRCS_DIR)/main_utils_3.c \
			  $(SRCS_DIR)/push.c \
			  $(SRCS_DIR)/swap.c \
			  $(SRCS_DIR)/complex_sort.c \
			  $(SRCS_DIR)/main_utils_1.c \
			  $(SRCS_DIR)/main_utils_4.c \
			  $(SRCS_DIR)/rev_rot.c \
			  $(SRCS_DIR)/helper_utils_1.c \
			  $(SRCS_DIR)/main_utils_2.c \
			  $(SRCS_DIR)/rot.c \
			  $(SRCS_DIR)/simple_sort.c \
			  $(SRCS_DIR)/medium_sort.c

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

all:	$(NAME)

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

.PHONY: all clean fclean re bonus b_clean b_fclean b_re
