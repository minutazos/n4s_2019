##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	= 	src/main.c		\
		src/utils/my_strlen.c	\
		src/utils/my_putstr.c	\
		src/utils/my_get_next_line.c	\
		src/utils/my_strcpy.c		\
		src/utils/tokenize_string.c	\
		src/utils/my_getnbr.c		\
		src/utils/my_strcmp.c		\
		src/commands.c		\
		src/ai.c			\
		src/simulation.c	\
		src/lidar.c			\
		src/car.c

OBJ 	=	$(SRC:.c=.o)

NAME	=	ai

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\n-------------\n"
	@echo -e "Building main program..."
	@echo -e "----------------------------------\n\n"
	gcc -o $(NAME) $(OBJ)

clean:
	@echo -e "\n-------------\n"
	@echo -e "Cleaning up objects..."
	@echo -e "----------------------------------\n\n"
	rm -rf $(OBJ)

fclean:	clean
	@echo -e "\n-------------\n"
	@echo -e "Cleaning main binary..."
	@echo -e "----------------------------------\n\n"
	rm -f $(NAME)

re: fclean all
