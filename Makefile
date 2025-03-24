INC=/usr/include
INCLIB=$(INC)/../lib
LFLAGS= -L.. -L$(INCLIB) -Lmlx -lmlx -lXext -lX11 -lm -Linc/get_next_line -lftgnl -Linc/ft_printf -lftprintf

SRCS = draw.c draw_hlpr.c draw_line.c events.c ft_atoi.c main.c parse.c projection.c utils.c
OBJS = $(SRCS:%.c=%.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
SAN = -fsanitize=address -g

TARGET = fdf

FT_PRINTF = ./inc/ft_printf/libftprintf.a
GNL = ./inc/get_next_line/libftgnl.address

all: $(LIBFT) $(FT_PRINTF) $(GNL) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -g $(OBJS) -o $(TARGET) $(SAN) $(LFLAGS)

$(FT_PRINTF):
	$(MAKE) -C inc/ft_printf

$(GNL):
	$(MAKE) -C inc/get_next_line

%.o: %.c
	$(CC) -g $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
