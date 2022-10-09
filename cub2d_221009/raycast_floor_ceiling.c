/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:48:45 by yukim             #+#    #+#             */
/*   Updated: 2022/10/09 13:48:45 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static unsigned int	get_rgbcode(int *arr)
{
	unsigned int color;

	color = 0;
	color = (color | (arr[0] & 0xFF)) << 8;
	color = (color | (arr[1] & 0xFF)) << 8;
	color = (color | (arr[2] & 0xFF));
	return (color);
}

void	floorcast(t_game *game, t_ray *ray)
{
	int			y;
	int			x;
	unsigned int	color;
	t_fl_ray	*fflo;

	y = 0;
	fflo = &(ray->flo);
	while(y < height)
	{
		x = 0;
		reset_floor(ray, fflo, y);
		while(x < width)
		{
			fflo->cell_x = (int)fflo->floor_x;
			fflo->cell_y = (int)fflo->floor_y;
			fflo->ftex_x = (int)(tex_width * (fflo->floor_x - fflo->cell_x)) & (tex_width - 1);
			fflo->ftex_y = (int)(tex_width * (fflo->floor_y - fflo->cell_y)) & (tex_height - 1);
			fflo->floor_x += fflo->floor_step_x;
			fflo->floor_y += fflo->floor_step_y;
			
			color = get_rgbcode(game->info.floor_color);
			color = (color >> 1) & 8355711;
			ray->tex.re_map[y][x] = color;

			color = get_rgbcode(game->info.ceiling_color);
			color = (color >> 1) & 8355711;
			ray->tex.re_map[height - y - 1][x] = color;
			
			x++;
		}
		y++;
	}
}

void	reset_floor(t_ray *ray, t_fl_ray *flo, int y)
{
	flo->ray_dir_x0 = ray->dir_x - ray->plane_x;
	flo->ray_dir_y0 = ray->dir_y - ray->plane_y;
	flo->ray_dir_x1 = ray->dir_x + ray->plane_x;
	flo->ray_dir_y1 = ray->dir_y + ray->plane_y;
	flo->row_distance = (0.5 * height) / (y - height / 2);
	flo->floor_step_x = flo->row_distance * (flo->ray_dir_x1 - flo->ray_dir_x0) / width;
	flo->floor_step_y = flo->row_distance * (flo->ray_dir_y1 - flo->ray_dir_y0) / width;
	flo->floor_x = ray->pl_x + flo->row_distance * flo->ray_dir_x0;
	flo->floor_y = ray->pl_y + flo->row_distance * flo->ray_dir_y0;
}