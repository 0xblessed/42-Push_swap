NAME= push_swap.a

SRC= push_swap.c	push_swap_utils.c	push_swap_coms.c

OBJ1=$(SRC:.c=.o)

OBJ=$(OBJ1:.m=.o)

$(NAME):	$(OBJ)
	@make -sC ./libft/
	@cp libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\033[36m"****************\\nCompiled...\\n****************\\n"\033[0m\n"

run:
	@clear
	@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@gcc -Wextra -Werror -Wall ./push_swap.c $(SRC) libft.a -o push_swap

bonus:
		@clear
		@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
		@gcc -Wextra -Werror -Wall ./checker.c $(SRC) libft.a -o checker

all: $(NAME)

clean:
	@rm -f $(NAME) $(OBJ)
	@make -sC ./libft/ fclean
	@clear
	@echo "\n\033[36m"****************\\nDeleted files...\\n****************\\n"\033[0m\n"

fclean: clean
		@rm -rf libft.a
		@rm -rf push_swap
		@rm -rf checker
		@rm -rf *.t
	
re: clean all

.PHONY: all clean re run