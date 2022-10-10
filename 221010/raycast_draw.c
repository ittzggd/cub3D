/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:53:49 by hejang            #+#    #+#             */
/*   Updated: 2022/10/10 14:33:29 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	raycast(t_game *game)
{
	init_ray_tex_struct(&(game->ray));
//	floorcast(game, &(game->ray));
	wallcast(game);
}

void	init_ray_tex_struct(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	while (i < ray->win_y)
	{
		j = 0;
		while (j < ray->win_x)
		{
			ray->tex.re_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	draw(t_game *game)
{
	t_mlx		*mmlx;
	t_img		*iimg;
	t_ray_tex	*ttex;
	int			x;
	int			y;

	mmlx = &(game->mlx);
	iimg = &(game->img);
	ttex = &(game->ray.tex);
	y = 0;
	while (y < game->ray.win_y)
	{
		x = 0;
		while (x < game->ray.win_x)
		{
			iimg->data[y * (int)game->ray.win_x + x] = ttex->re_map[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mmlx->mlx, mmlx->mlx_win, iimg->img_ptr, 0, 0);
}