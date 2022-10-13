/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:50:43 by yukim             #+#    #+#             */
/*   Updated: 2022/10/13 19:23:46 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static void	reset_wall(t_ray *ray, int x);
static void	set_wallcast_var(t_ray *ray, int *hit);

void	wallcast(t_game *game)
{
	int		x;
	int		hit;
	t_ray	*ray;

	ray = &(game->ray);
	x = 0;
	while (x < ray->win_x)
	{
		reset_wall(ray, x);
		set_wallcast_var(ray, &hit);
		while (hit == 0)
			hit = is_hit(game, ray);
		if (ray->side == 0)
			ray->prep_wall_dist = (ray->map_x - ray->pl_x \
								+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
		else
			ray->prep_wall_dist = (ray->map_y - ray->pl_y \
								+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
		tex_wall(ray);
		coordinate_tex(game, ray, x);
		x++;
	}
}

static void	reset_wall(t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)ray->win_x - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pl_x;
	ray->map_y = (int)ray->pl_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	set_wallcast_var(t_ray *ray, int *hit)
{
	*hit = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pl_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pl_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pl_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pl_y) * ray->delta_dist_y;
	}
}
