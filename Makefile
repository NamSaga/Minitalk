SERVER = server
CLIENT = client

CLIENTS_SRC = src/client.c utils.c
SERVER_SRC = src/server.c utils.c

PRINTF_DIR = lib/printf/libftprintf.a
LIBFT_DIR = lib/libft/libft.a

CLIENT_OBJS = $(CLIENTS_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f src/*.o lib/*.o

INCLUDE = -I include

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \e[0m
YELLOW = \e[38;5;226m
INFO = [$(YELLOW)Info$(RESET)]
SUCCESS = [$(GREEN)Succes$(RESET)]

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SERVER_OBJS)
			@make -C ./lib/printf
			@make -C ./lib/libft
			cc $(CFLAGS) $(SERVER_OBJS) $(INCLUDE) $(PRINTF_DIR) -o $(SERVER) -g
			@printf "$(SUCCESS) server created ✅\n"

$(CLIENT): $(CLIENT_OBJS)
			@make -C ./lib/printf
			@make -C ./lib/libft
			cc $(CFLAGS) $(CLIENT_OBJS) $(INCLUDE) $(PRINTF_DIR) -o $(CLIENT) -g
			@printf "$(SUCCESS) client created ✅\n"

clean:
		@make -C ./lib/printf clean
		@make -C ./lib/libft clean
		$(RM)
		@printf "$(INFO) object files removed 🛑\n"

fclean: clean
		@make -C ./lib/printf fclean
		@make -C ./lib/libft fclean
		rm -f $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all
	@printf "$(INFO) Reset succesfully"
