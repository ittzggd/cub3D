/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:38:35 by yukim             #+#    #+#             */
/*   Updated: 2022/10/10 00:48:54 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

#define R_LEFT	0
#define R_RIGHT	1

static void	copy_struct_contents(t_ray *origin, t_ray* copy);
static void	save_cos_sin(t_ray *rray, double *ccos, double *ssin, int r_dir);

void rotate_camera(t_game *game)
{
	t_ray	*rray;
	t_ray	*copy;
	double	ccos;
	double	ssin;

	rray = &(game->ray);
	copy_struct_contents(rray, copy);
	if (game->key_flag.rotate_left == TRUE)
	{
		save_cos_sin(rray, &ccos, &ssin, R_LEFT);
		game->key_flag.rotate_left = FALSE;
	}
	else if (game->key_flag.rotate_right == TRUE)
	{
		save_cos_sin(rray, &ccos, &ssin, R_RIGHT);
		game->key_flag.rotate_right = FALSE;
	}
	rray->dir_x = (rray->dir_x * ccos) - (rray->dir_y * ssin);
	rray->dir_y = (copy->dir_x * ssin) + (rray->dir_y * ccos);
	rray->plane_x = (rray->plane_x * ccos) - (rray->plane_y * ssin);
	rray->plane_y = (copy->plane_x * ssin) + (rray->plane_y * ccos);
	rray->x_dir_x = (rray->x_dir_x * ccos) - (rray->x_dir_y * ssin);
	rray->x_dir_y = (copy->x_dir_x * ssin) + (rray->x_dir_y * ccos);
}

static void	copy_struct_contents(t_ray *origin, t_ray* copy)
{
	copy->pl_x = origin->pl_x;
	copy->pl_y = origin->pl_y;
	copy->plane_x = origin->plane_x;
	copy->plane_y = origin->plane_y;
	copy->dir_x = origin->dir_x;
	copy->dir_y = origin->dir_y;
	copy->x_dir_x = origin->x_dir_x;
	copy->x_dir_y = origin->x_dir_y;
}

static void	save_cos_sin(t_ray *rray, double *ccos, double *ssin, int r_dir)
{
	if (r_dir == R_LEFT)
	{
		*ccos = cos(-(rray->turn_speed));
		*ssin = sin(-(rray->turn_speed));
	}
	else if (r_dir == R_RIGHT)
	{
		*ccos = cos(rray->turn_speed);
		*ssin = sin(rray->turn_speed);
	}	
}