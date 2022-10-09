/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untextured_raycast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:53:49 by hejang            #+#    #+#             */
/*   Updated: 2022/10/03 18:57:08 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


void	raycast(t_game *game);
void	draw(t_game *game);
void	init_ray_tex_struct(t_ray *ray);

void	raycast(t_game *game)
{
	init_ray_tex_struct(game->ray);
	floorcast(game, &(game->ray));
	wallcast(game);
}

void	draw(t_game *game)
{
	t_mlx		*mmlx;
	t_img		*iimg;
	t_ray_tex  	*ttex;
	int		x;
	int		y;

	mmlx = &(game->mlx);
	iimg = &(game->img);
	ttex = &(game->ray.tex);
	y = 0;
	while(y < game->ray->win_y)
	{
		x = 0;
		while(x < game->ray->win_x)
		{
			iimg->data[y * game->ray->win_x + x] = ttex->re_map[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mmlx->mlx, mmlx->mlx_win, iimg->img_ptr, 0, 0);
}

void	init_ray_tex_struct(t_ray *ray)
{
	for (int i = 0; i < ray->win_y; i++)
	{
		for (int j = 0; j < ray->win_x; j++)
		{
			ray->tex.re_map[i][j] = 0;
		}
	}
}