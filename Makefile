# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 04:19:13 by bkaztaou          #+#    #+#              #
#    Updated: 2023/07/31 23:50:04 by bkaztaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLXLIB = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT = -Llibft -lft
RM = rm -rf

FILES = $(wildcard ./src/*.c) $(wildcard ./utils/*.c)
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXLIB) $(LIBFT)

clean:
	$(MAKE) -C ./libft fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
