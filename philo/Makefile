NAME := philo

FLAGS := -Wall -Werror -Wextra

CC := gcc

DIR_OBJ := obj
HEADER := philosofers.h

SRC := ft_atoi.c	  \
		main.c		  \
		philosofs.c	  \
		thread_func.c \
		time.c		  \
		utils.c

OBJ := $(addprefix $(DIR_OBJ)/,$(SRC:.c=.o))

all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(HEADER) $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re