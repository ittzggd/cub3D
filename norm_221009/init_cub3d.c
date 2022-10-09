/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:22:37 by yukim             #+#    #+#             */
/*   Updated: 2022/10/09 21:22:37 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static void	init_windowsize(t_game *game, t_mlx *mmlx);
static void	init_ray(t_game *game);
static void	init_malloc_re_map(t_game *game);

void	init_cub3d(t_game *game)
{
	init_map(game, &(game->map), &(game->info));
	if (is_valid_map(game->map) == ERROR)
		ft_error("[Error] Invalid map\n");
	init_windowsize(game, &(game->mlx));
	init_ray(t_game *game);
	load_texture(game);
	load_window(game);
	init_malloc_re_map(game);
}

void	save_dir_vector(t_game *game, char dir)
{
	if (dir == 'W')
	{
		game->ray.dir_x = -1;
		game->ray.dir_y = 0;
	}
	else if (dir == 'E')
	{
		game->ray.dir_x = 1;
		game->ray.dir_y = 0;
	}
	else if (dir == 'N')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = -1;
	}
	else if (dir == 'S')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = 1;
	}
	game->ray.x_dir_x = game->ray.dir_y;
	game->ray.x_dir_y = -(game->ray.dir_x);
}

static void	init_windowsize(t_game *game, t_mlx *mmlx)
{
	mmlx->window_height = 640 * 2;
	mmlx->window_width = 480 * 2;
}

static void	init_ray(t_game *game)
{
	game->ray.pl_x = game->map->sp_x + 0.5;
	game->ray.pl_y = game->map->sp_y + 0.5;
	game->ray.win_x = game->mlx.window_width;
	game->ray.win_y = game->mlx.window_height;
	game->ray.turn_speed = 0.05;
	game->ray.move_speed = 0.05;
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66;
}

static void	init_malloc_re_map(t_game *game)
{
	int		i;

	i = 0;
	game->ray.tex.re_map \
					= (int **)malloc(sizeof(int *) * (game->ray.win_y + 1));
	if (game->ray.tex.re_map == NULL)
		ft_error("[1][func : init_malloc_re_map] malloc failed.");
	while (i < game->ray.win_y)
	{
		game->ray.tex.re_map[i] = (int *)malloc(sizeof(int) * game->ray.win_x);
		if (game->ray.tex.re_map[i] == NULL)
			ft_error("[2][func : init_malloc_re_map] malloc failed.");
		i++;
	}
	game->ray.tex.re_map[i] = NULL;
	init_ray_tex_struct(ray);
}