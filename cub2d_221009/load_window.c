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

void	save_px_py_as_pixel(t_game *game, int tile_size);

void	load_window(t_game *game)
{
	int	tile_size;
	t_mlx	*mmlx;
	t_img	*iimg;

	// struct init
	mmlx = &(game->mlx);
	iimg = &(game->img);
	tile_size = 64;
	mmlx->window_height = game->map->max_height * tile_size;
	mmlx->window_width = game->map->max_width * tile_size;
	save_px_py_as_pixel(game, 64);

	// mlx init
	mmlx->mlx = mlx_init();
		// if window_width > monitor screen || window_height > monitor screen =>  ??
	mmlx->mlx_win = mlx_new_window(mmlx->mlx, mmlx->window_width, mmlx->window_height, "cub3D");
	iimg->img_ptr = mlx_new_image(mmlx->mlx, mmlx->window_width, mmlx->window_height);
	iimg->data = (int *)mlx_get_data_addr((iimg->img_ptr), &(iimg->bpp), &(iimg->size_line), &(iimg->endian));

// [init map] function saved player's start direction 
// [save_px_py_as_pixel] function saved player's start position

}

void	save_px_py_as_pixel(t_game *game, int tile_size)
{
	int	x;
	int	y;
	x = game->map->sp_x; // start player x
	y = game->map->sp_y; // start player y

	game->ray.pl_x = (x * tile_size) + (tile_size / 2);
	game->ray.pl_y = (y * tile_size) + (tile_size / 2);
//	game->ray.turn_speed = 4 * (M_PI / 180);
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66;
	game->ray.move_speed = 0.05;
	game->ray.turn_speed = 0.05;
}
