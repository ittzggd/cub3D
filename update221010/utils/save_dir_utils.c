/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_dir_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:09:10 by hejang            #+#    #+#             */
/*   Updated: 2022/10/16 15:17:50 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dir_w(t_game *game, char dir)
{
	if (dir == 'W')
	{
		game->ray.dir_x = -1;
		game->ray.dir_y = 0;
		game->ray.plane_x = 0;
		game->ray.plane_y = -0.66;
	}
}

void	dir_e(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->ray.dir_x = 1;
		game->ray.dir_y = 0;
		game->ray.plane_x = 0;
		game->ray.plane_y = 0.66;
	}
}

void	dir_n(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = -1;
		game->ray.plane_x = 0.66;
		game->ray.plane_y = 0;
	}
}

void	dir_s(t_game *game, char dir)
{
	if (dir == 'S')
	{
		game->ray.dir_x = 0;
		game->ray.dir_y = 1;
		game->ray.plane_x = -0.66;
		game->ray.plane_y = 0;
	}
}
