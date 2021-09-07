NAME  = cub3D
BONUS = cub3D_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra

MLX = ./srcs/mlx/
INC_MLX = -L${MLX} -lmlx -framework OpenGL -framework Appkit 
INCS = -I./srcs -I./srcs/gnl -I./srcs/mlx -I./srcs/util
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRCS = ./srcs/cast_rest \
		./srcs/cast_wall \
		./srcs/cast \
		./srcs/check_valid \
		./srcs/init \
		./srcs/key_controller \
		./srcs/main \
		./srcs/parser \
		./srcs/save \
		./srcs/gnl/gnl \
		./srcs/util/util_algorithms \
		./srcs/util/util_ctype \
		./srcs/util/util_memory \
		./srcs/util/util_stdlib \
		./srcs/util/util_string

SRCS_S = $(addsuffix .c, $(SRCS))
OBJS = $(SRCS_S:.c=.o)

all: $(NAME)

${NAME}:${OBJS}
	make -C ${MLX}
	$(CC) $(CFLAGS) ${INCS} ${INC_MLX} -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) *.bmp
	make -C $(MLX) clean
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re