NAME = libgarbage.a
SRC = gextend.c gfree.c ginit.c gmalloc.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ) : $(SRC)
	@gcc -Wall -Wextra -Werror -I. -c $(SRC)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
