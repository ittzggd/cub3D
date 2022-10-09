/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:04:32 by yukim             #+#    #+#             */
/*   Updated: 2022/10/08 20:04:32 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"

void move_left_or_right(t_game *game);

void move_left_or_right(t_game *game)
{
	t_ray	*rray;
	double		new_x;
	double		new_y;

	if (game->key_flag.move_left == TRUE)
	{
		new_x = rray->pl_x + (rray->x_dir_x * rray->move_speed) + 0.00001;
		new_y = rray->pl_y + (rray->x_dir_y * rray->move_speed) + 0.00001;
		game->key_flag.move_left = FALSE;
	}
	else if (game->key_flag.move_right == TRUE)
	{
		new_x = rray->pl_x - (rray->x_dir_x * rray->move_speed) + 0.00001;
		new_y = rray->pl_y - (rray->x_dir_y * rray->move_speed) + 0.00001;
		game->key_flag.move_right = FALSE;
	}
	if ((game->map->maps[(int)new_x][(int)(rray->pl_y)] == '0') && (game->map->maps[(int)(rray->pl_x)][(int)new_y] == '0'))
	{
		rray->pl_x = new_x;
		rray->pl_y = new_y;
	}
}
