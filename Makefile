# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 21:55:03 by hejang            #+#    #+#              #
#    Updated: 2022/09/19 21:56:02 by hejang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm 
RMFLAGS = -f

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C ./libft
		$(MAKE) -C ./mlx 
		$(CC) $(CFLAGS) -Llibft -lft -Lmlx -lmlx -framework OpenGl -framework AppKit -Imlx $(OBJS) -o $(NAME)

clean :
		$(MAKE) -C ./libft clean
		$(MAKE) -C ./mlx clean
		$(RM) $(RMFLAG) $(OBJS)

fclean : clean
		$(MAKE) -C ./libft fclean
		$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re