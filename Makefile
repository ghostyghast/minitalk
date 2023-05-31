SRC_CLIENT = client.c

SRC_SERVER = server.c

CLIENT = client

SERVER = server

INCLUDES = -Ilibft -L./libft -lft

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

OBJS_SERVER = $(SRC_SERVER:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(CLIENT): $(OBJS_CLIENT) $(SERVER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_CLIENT) -o $@

$(SERVER): $(OBJS_SERVER) 
	@make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_SERVER) -o $@

all : $(CLIENT) 

clean : 
	@make clean -C ./libft
	@rm -f *.o

fclean : clean
	@make fclean -C ./libft
	@rm -f $(CLIENT) $(SERVER)

re : fclean
	make

.PHONY: all clean fclean re