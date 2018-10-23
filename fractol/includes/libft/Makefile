NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
RM = rm -f
DSRCS = .

SRCS = $(shell ls -1 $(DSRCS) | grep .c$$)

OBJ = $(SRCS:%.c=%.o)
	
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean   
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
