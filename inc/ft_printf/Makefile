CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

SRCS = ft_printf.c \
		helpers/ft_get_number_len.c \
		helpers/ft_init_number.c \
		helpers/ft_is_flag.c \
		helpers/ft_max.c \
		helpers/ft_print_n.c \
		helpers/ft_render_number.c \
		helpers/ft_write_prefix.c \
		helpers/ft_init_form.c \
		helpers/ft_is_digit.c \
		helpers/ft_is_in.c \
		helpers/ft_parse_number.c \
		helpers/ft_print_number_base.c \
		helpers/ft_spec_strlen.c \
		helpers/ft_render_sign.c \
		msrvs/ft_parse_format.c \
		msrvs/ft_print_char.c \
		msrvs/ft_print_number.c \
		msrvs/ft_print_string.c \
		msrvs/ft_spec_atoi.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
