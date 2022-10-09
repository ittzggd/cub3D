/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:50:43 by yukim             #+#    #+#             */
/*   Updated: 2022/10/09 13:50:43 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	wallcast(t_game *game)
{
	int		x;
	int		hit;
	int		side;
	double	prep_wall_dist;
	t_ray	*ray;

	ray = &(game->ray);
	x = 0;
	while (x < ray->win_x)
	{
		reset_wall(ray, x);
		hit	= 0;
		if(ray->ray_dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (ray->pl_x - ray->map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (ray->map_x + 1.0 - ray->pl_x) * ray->delta_dist_x;
		}
		if(ray->ray_dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (ray->pl_y - ray->map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = (ray->map_y + 1.0 - ray->pl_y) * ray->delta_dist_y;
		}
		while(hit == 0)
			hit = is_hit(game, ray);


		if(ray->side == 0)
			prep_wall_dist = (ray->map_x - ray->pl_x + ( 1 - ray->step_x) / 2) / ray->ray_dir_x;
		else
			prep_wall_dist = (ray->map_y - ray->pl_y + ( 1 - ray->step_y) / 2) / ray->ray_dir_y;
		
		tex_wall(game, ray);

		coordinate_tex(game, ray, x);

		x++;	
	}
}

void	reset_wall(t_ray	*ray, int x)
{
	ray->camera_x = 2 * x / (double)width - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_y;
	ray->map_x = (int)ray->pl_x;
	ray->map_y = (int)ray->pl_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

int	is_hit(t_game *game, t_ray *ray)
{
	int	ret;

	ret = 0;
	if(ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0; // 	x
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1; // y
	}
	
	if(game->map.maps[ray->map_x][ray->map_y] == '1')
		ret == 1;
	return (ret);
}


void	tex_wall(t_game *game, t_ray *ray)
{
	t_ray_tex	*ttex;

	ttex = &(ray->tex);

	ttex->line_height = (int)height / ray->prep_wall_dist;

	ttex->draw_start = -(ttex->line_height) / 2 + height / 2;
	if (ttex->draw_start < 0)
		ttex->draw_start = 0;

	ttex->draw_end = ttex->line_height / 2 + height / 2;
	if (ttex->draw_end >= height)
		ttex->draw_end = height - 1;

	ttex->tex_idx = ft_get_texture(ray) - 10;

	if(ray->side == 0)
		ttex->wall_x = ray->pl_y + ray->prep_wall_dist * ray->ray_dir_y;
	else
		ttex->wall_x = ray->pl_x + ray->prep_wall_dist * ray->ray_dir_x;
	ttex->wall_x -= floor(ttex->wall_x);
}

void	coordinate_tex(t_game *game, t_ray *ray, int x)
{
	t_ray_tex	*ttex;
	double		step;
	unsigned int	color;
	int			y;

	ttex = &(ray->tex);
	ttex->tex_x = (int)(ttex->wall_x * tex_width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		ttex->tex_x = tex_width - ttex->tex_x - 1;

	step = 1.0 * tex_height / ttex->line_height;
	ttex->tex_pos = (ttex->draw_start - height / 2 + ttex->line_height / 2) * step;
	y = ttex->draw_start;
	while (y < ttex->draw_end)
	{
		ttex->tex_y = (int)ttex->tex_pos & (tex_height - 1);
		ttex->tex_pos += step;
		color = game->tex[ttex->tex_idx].tex_data[tex_height * (int)ttex->tex_y + (int)ttex->tex_x];
		if(ray->side == 1)
			color = (color >> 1) & 8355711; // make color darker for y-sides
		ttex->re_map[y][x] = color;
		y++;
	}
}

int	ft_get_texture(t_ray *ray)
{
	if (ray->side == 1)
	{
		if(ray->ray_dir_y < 0)
			return (TEXTURE_NO);
		else
			return (TEXTURE_SO);
	}
	else
	{
		if(ray->ray_dir_x < 0)
			return (TEXTURE_WE);
		else
			return (TEXTURE_EA);
	}
}