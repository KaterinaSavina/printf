NAME	=	libft.a

FILES 	=	ft_isdigit.c\
			ft_strlen.c\
			ft_toupper.c\
			ft_strdup.c \


OBJECTS = $(FILES:.c=.o)

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc -I $(HEADER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
clean:
	@/bin/rm -f $(OBJECTS)
	@echo .o has cleaned
fclean: clean
	@/bin/rm -f $(NAME)
	@echo libft.a has cleaned
re: fclean all

.PHONY: all clean fclean re
