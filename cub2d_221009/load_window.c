/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:41:17 by hejang            #+#    #+#             */
/*   Updated: 2022/10/03 18:56:44 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


void	load_window(t_game *game)
{
	t_mlx	*mmlx;
	t_img	*iimg;

	// struct init
	mmlx = &(game->mlx);
	iimg = &(game->img);
	mmlx->window_height = 640;
	mmlx->window_width = 480;
	
	game->ray.pl_x = game->map->sp_x + 0.5;
	game->ray.pl_y = game->map->sp_y + 0.5;
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66;
	game->ray.move_speed = 0.05;
	game->ray.turn_speed = 0.05;

	// mlx init
	mmlx->mlx = mlx_init();
	mmlx->mlx_win = mlx_new_window(mmlx->mlx, mmlx->window_width, mmlx->window_height, "cub3D");
	iimg->img_ptr = mlx_new_image(mmlx->mlx, mmlx->window_width, mmlx->window_height);
	iimg->data = (int *)mlx_get_data_addr((iimg->img_ptr), &(iimg->bpp), &(iimg->size_line), &(iimg->endian));

// [init map] function saved player's start direction 
}
