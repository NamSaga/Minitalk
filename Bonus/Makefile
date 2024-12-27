SERVER = server
CLIENT = client

CLIENTS_SRC = src/client.c src/utils.c src/libft.c
SERVER_SRC = src/server.c src/utils.c src/libft.c

PRINTF_DIR = lib/printf/libftprintf.a
LIBFT_DIR = lib/libft/libft.a

CLIENT_OBJS = $(CLIENTS_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f src/*.o lib/*.o

INCLUDE = -I include

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
			@make -C ./lib/printf
			cc $(CFLAGS) $(SERVER_OBJS) $(INCLUDE) $(PRINTF_DIR) -o $(SERVER) -g

$(CLIENT): $(CLIENT_OBJS)
			@make -C ./lib/printf
			cc $(CFLAGS) $(CLIENT_OBJS) $(INCLUDE) $(PRINTF_DIR) -o $(CLIENT) -g

clean:
		@make -C ./lib/printf clean
		$(RM)

fclean: clean
		@make -C ./lib/printf fclean
		rm -f $(SERVER) $(CLIENT)

re: fclean all
