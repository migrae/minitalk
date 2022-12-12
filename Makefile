RM 			= 	rm -f
CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror
AR			= 	ar
ARFLAGS 	= 	-rcs
INCFLAG		= 	-I .

NAME 		= 	server
NAME2		=	client

SRC1 		:= 	server.c
SRC2		:=	client.c 

OBJ1		= $(SRC1:.c=.o)
OBJ2		= $(SRC2:.c=.o)

all: make-libft $(NAME) ${NAME2}

make-libft:
	@bash -c "make -s -C libft"

$(NAME): $(OBJ1)
	@$(CC) $(OBJ1) libft/libft.a -o $(NAME)

$(NAME2): $(OBJ2)
	@$(CC) $(OBJ2) libft/libft.a -o $(NAME2)

$(OBJ1): $(SRC1)
	@$(CC) -c $^ $(CFLAGS)

$(OBJ2): $(SRC2)
	@$(CC) -c $^ $(CFLAGS)

clean:
	- @$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	- @$(RM) ${NAME} ${NAME2}

re: fclean all

.PHONY: all clean fclean re make-libft
