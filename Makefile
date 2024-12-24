CLIENT = client
SERVER = server

CFLAGS = -Wall -Wextra -Werror
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/header -LS$(PRINTF) -lprintf

PRINTF = printf

all :
			@make -s -C $(PRINTF)
			@gcc $(FLAGS) client.c -o $(CLIENT)	
			@gcc $(FLAGS) server.c -o $(SERVER)

clean :
			@make clean -s -C $(PRINTF)

fclean :	clean
		 	@make fclean -s -C(PRINTF)
			@rm -f $(SERVER) $(CLIENT)

re : fclean all

gcc -o server server.c -Wall -Wextra -Werror -Lprintf -lftprintf -Llibft -lft

