NAME = libutil.a

CFLAGS = -Wall -Werror -Wextra
CC = gcc
AR = ar rc
RM = rm -f

SRCS_S = ./util_algorithm \
		./util_ctype \
		./util_print \
		./util_stdlib \
		./util_string

SRCS = $(addsuffix .c, $(SRCS_S))


OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(AR) $@ $^

.c.o: $(SRCS)
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re