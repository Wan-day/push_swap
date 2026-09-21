CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)
RM			= rm -f

SRCS_DIR		= main
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
			  $(SRCS_DIR)/operations_1.c \
			  $(SRCS_DIR)/rot.c
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF_DIR	= ft_printf/includes
PRINTF		= $(PRINTF_DIR)/ft_printf.a
LIBS		= $(PRINTF) $(LIBFT)
TARGET		= push_swap

OBJS 		= $(SRCS:.c=.o)

all:	$(TARGET)

$(TARGET): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(TARGET)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

$(SRC_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean:	clean
	$(RM) $(TARGET)    
	make -C libft fclean
	make -C ft_printf fclean


re:	fclean all

.PHONY: all clean fclean re

