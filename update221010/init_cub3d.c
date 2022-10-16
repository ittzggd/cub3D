/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:22:37 by yukim             #+#    #+#             */
/*   Updated: 2022/10/16 15:17:06 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static void	init_windowsize(t_mlx *mmlx);
static void	init_ray(t_game *game);
static void	init_malloc_re_map(t_game *game);

void	init_cub3d(t_game *game)
{
	init_map(game, &(game->map), &(game->info));
	if (is_valid_map(&(game->map)) == ERROR)
		ft_error("[Error] Invalid map\n");
	init_windowsize(&(game->mlx));
	init_ray(game);
	load_window(game);
	load_texture(game);
	init_malloc_re_map(game);
}

void	save_dir_vector(t_game *game, char dir)
{
	if (dir == 'W')
		dir_w(game, dir);
	else if (dir == 'E')
		dir_e(game, dir);
	else if (dir == 'N')
		dir_n(game, dir);
	else if (dir == 'S')
		dir_s(game, dir);
	game->ray.x_dir_x = game->ray.dir_y;
	game->ray.x_dir_y = -(game->ray.dir_x);
}

static void	init_windowsize(t_mlx *mmlx)
{
	mmlx->mlx = mlx_init();
	mmlx->window_height = 480 ;
	mmlx->window_width = 640 ;
}

static void	init_ray(t_game *game)
{
	game->ray.pl_x = game->map.sp_x;
	game->ray.pl_y = game->map.sp_y + 0.5;
	game->ray.win_x = game->mlx.window_width;
	game->ray.win_y = game->mlx.window_height;
	game->ray.turn_speed = 0.2;
	game->ray.move_speed = 0.2;
	game->img.width = TEX_WIDTH;
	game->img.height = TEX_HEIGHT;
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
	init_ray_tex_struct(&(game->ray));
}
