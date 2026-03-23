CC = cc
CFLAGS = -Wall -Werror -Wextra

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

SERVER_OBJ = $(SERVER_SRCS:.c=.o)
CLIENT_OBJ = $(CLIENT_SRCS:.c=.o)

all: server client

server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o server

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o client

clean:
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: all clean fclean re