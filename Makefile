NAME	:= client
NAME2	:= server
SRCS	:= client.c
SRCS2	:= server.c
OBJS	:= $(SRCS:.c=.o)
OBJS2	:= $(SRCS2:.c=.o)

CC		:= gcc
CFLAGS	:= -Werror -Wall -Wextra

.PHONY: all
all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean: 
	$(RM) *.o

.PHONY: fclean
fclean: clean
	$(RM) $(NAME) $(NAME2)

.PHONY: re
re: fclean all