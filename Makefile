NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_printf_char.c \
				ft_printf_hex.c \
				ft_printf_int.c \
				ft_printf_long_itoa.c \
				ft_printf_pointer.c \
				ft_printf_t_tp.c \
				ft_printf_type.c \
				ft_printf_uint.c \
				ft_printf_utils.c \

LIB_DIR 	= ./libft
HEADER 		= ./ft_printf.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@make re -C $(LIB_DIR)
			@cp $(LIB_DIR)/libft.a $(NAME)
			@ar rcs $(NAME) $(OBJS)

%.o:		%.c ft_printf.h
			gcc $(CFLAGS) $(OPTFLAGS) -I $(HEADER) -c $< -o $@

clean:
			@rm -f $(OBJS)
			@make clean -C $(LIB_DIR)

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C $(LIB_DIR)

re:			fclean all

.PHONY: all clean fclean re
