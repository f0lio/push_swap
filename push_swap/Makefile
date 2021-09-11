
.PHONEY: all clean fclean re bonus

NAME	= push_swap
FLAGS	= -Werror -Wextra -Wall
FILES	= 	*.c

SRC		= $(FILES:%.c=./src/%.c) ../utils/src/*

DBG		= ../DBG/DBG.C -I../DBG/

$(NAME): $(SRC)
	@gcc -o $(NAME) $(SRC) $(DBG) -I./include -I../utils/include #-fsanitize=address #$(FLAGS)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@-rm -f $(NAME)

re: fclean all