# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hejang <hejang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 21:55:03 by hejang            #+#    #+#              #
#    Updated: 2022/10/17 10:43:33 by hejang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework Appkit

SRCS = main.c \
		key.c raycast_floor_ceiling.c load.c move.c raycast_wall.c \
		raycast_wall_utils.c init_cub3d.c raycast_draw.c rotate.c \
		./utils/ft_bzero.c ./utils/ft_str_func.c ./utils/get_next_line.c \
		./utils/is_utils.c ./utils/utils.c ./utils/save_dir_utils.c \
		./parsing/check_argument.c ./parsing/get_text_type.c ./parsing/map.c \
		./parsing/second_pos_info_utils.c ./parsing/check_map_wall.c \
		./parsing/init_info.c ./parsing/second_pos_info.c ./parsing/skip.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :$(OBJS)
	$(MAKE) -C mlx
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(MAKE) -C mlx clean
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(OBJS) $(NAME)

re : fclean all

.PHONY : all clean fclean re
