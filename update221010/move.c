/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:25:55 by yukim             #+#    #+#             */
/*   Updated: 2022/10/10 17:04:43 by yukim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	move_forward_or_backward(t_game *game)
{
	t_ray		*rray;
	double		new_x;
	double		new_y;

	rray = &(game->ray);
	new_x = rray->pl_x - rray->dir_x * rray->move_speed + 0.005;
	new_y = rray->pl_y - rray->dir_y * rray->move_speed + 0.005;
	game->key_flag.move_backward = FALSE;
	if (game->key_flag.move_forward == TRUE)
	{
		new_x = rray->pl_x + rray->dir_x * rray->move_speed + 0.005;
		new_y = rray->pl_y + rray->dir_y * rray->move_speed + 0.005;
		game->key_flag.move_forward = FALSE;
	}
	if ((game->map.maps[(int)new_x][(int)(rray->pl_y)] == '0') \
			&& (game->map.maps[(int)(rray->pl_x)][(int)new_y] == '0'))
	{
		rray->pl_x = new_x;
		rray->pl_y = new_y;
	}
}

void	move_left_or_right(t_game *game)
{
	t_ray		*rray;
	double		new_x;
	double		new_y;

	rray = &(game->ray);
	new_x = rray->pl_x + (rray->x_dir_x * rray->move_speed) + 0.005; // 0.00001이 값 조절하면서 역할 체크
	new_y = rray->pl_y + (rray->x_dir_y * rray->move_speed) + 0.005;
	game->key_flag.move_left = FALSE;
	if (game->key_flag.move_right == TRUE)
	{
		new_x = rray->pl_x - (rray->x_dir_x * rray->move_speed) + 0.005;
		new_y = rray->pl_y - (rray->x_dir_y * rray->move_speed) + 0.005;
		game->key_flag.move_right = FALSE;
	}
	if ((game->map.maps[(int)new_x][(int)(rray->pl_y)] == '0') \
			&& (game->map.maps[(int)(rray->pl_x)][(int)new_y] == '0'))
	{
		rray->pl_x = new_x;
		rray->pl_y = new_y;
	}
}
