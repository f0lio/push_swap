
.PHONEY: all clean fclean re bonus

all:
	@$(MAKE) -C push_swap/
	@$(MAKE) -C checker/

clean:
	@$(MAKE) -C push_swap/ clean
	@$(MAKE) -C checker/ clean

fclean: clean
	@$(MAKE) -C push_swap/ fclean
	@$(MAKE) -C checker/ fclean

re: fclean all