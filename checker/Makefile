
.PHONEY: all clean fclean re bonus

NAME	= checker
FLAGS	= -Werror -Wextra -Wall
FILES	=	checker.c operations.c instructions.c\
			error_handlers.c stdin_handlers.c\
			swap_actions.c push_actions.c\
			rotation_actions.c rev_rotation_actions.c
SRC		= $(FILES:%.c=./src/%.c) ../utils/src/*

$(NAME): $(SRC)
	@gcc -o $(NAME) $(SRC) -I./include -I../utils/include #$(FLAGS)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@-rm -f $(NAME)

re: fclean all
