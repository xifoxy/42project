CC = clang
FLAGS = -Wall -Wextra -Werror -g -c
NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_printf_util.c \
		ft_printf_type_string.c \
		ft_printf_type_num.c \
		ft_printf_string_parser.c \
		ft_printf_num_utill.c \
		ft_printf_memory_util.c
OBJS = $(SRCS:.c=.o)

$(NAME): all

%.o: %.c
	$(CC) $< $(FLAGS) -o $@ -I ./includes
all: $(OBJS)
	@ar -rcs $(NAME) $^
clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)
re: fclean
	@make all
.PHONY: all clean fclean re