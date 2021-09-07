SERVER = server
CLIENT = client
SERVER_B = server_bonus
CLIENT_B = client_bonus

CFLAGS = -Wall -Werror -Wextra
CC = gcc

SRCS_SERVER = ./server.c \
				./server_util.c
SRCS_CLIENT = ./client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER_B = ./server_bonus.c \
				./server_util_bonus.c
SRCS_CLIENT_B = ./client_bonus.c
OBJS_SERVER_B = $(SRCS_SERVER_B:.c=.o)
OBJS_CLIENT_B = $(SRCS_CLIENT_B:.c=.o)

util:
	@make -C ./util
	
all: util $(SERVER) $(CLIENT)
$(SERVER): $(OBJS_SERVER)
	@$(CC) -o $@ $^ -Lutil -lutil -I./util
$(CLIENT): $(OBJS_CLIENT)
	@$(CC) -o $@ $^ -Lutil -lutil -I./util

bonus: util $(SERVER_B) $(CLIENT_B)
$(SERVER_B): $(OBJS_SERVER_B)
	@$(CC) -o $@ $^ -Lutil -lutil -I./util
$(CLIENT_B): $(OBJS_CLIENT_B)
	@$(CC) -o $@ $^ -Lutil -lutil -I./util

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@rm -f *.o
	@make -C ./util/ clean

fclean: clean
	@rm -f $(SERVER) $(SERVER_B) $(CLIENT) $(CLIENT_B)
	@make -C ./util/ fclean

re: fclean all

.PHONY: util bonus all clean fclean re