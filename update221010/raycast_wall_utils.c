/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:17:01 by yukim             #+#    #+#             */
/*   Updated: 2022/10/12 21:07:25 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int	ft_get_texture(t_ray *ray);
static void	set_coor_tex_var(t_ray_tex *ttex, double *step, t_ray *ray);

int	is_hit(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
	// if(ray->map_x > game->map.max_height)
	// 	ray->map_x = game->map.max_height - 1;
	// if(ray->map_y > game->map.max_width)
	// 	ray->map_y = game->map.max_width - 1;
	if (game->map.maps[(int)ray->map_y][(int)ray->map_x] == '1'
		||game->map.maps[(int)ray->map_y][(int)ray->map_x] == ' '
		||game->map.maps[(int)ray->map_y][(int)ray->map_x] == '\t')
		hit = 1;
	return (hit);
}

void	tex_wall(t_ray *ray)
{
	t_ray_tex	*ttex;

	ttex = &(ray->tex);
	ttex->line_height = (int)(ray->win_y / ray->prep_wall_dist);
	ttex->draw_start = -(ttex->line_height) / 2 + ray->win_y / 2;
	if (ttex->draw_start < 0)
		ttex->draw_start = 0;
	ttex->draw_end = ttex->line_height / 2 + ray->win_y / 2;
	if (ttex->draw_end >= ray->win_y)
		ttex->draw_end = ray->win_y - 1;
	ttex->tex_idx = ft_get_texture(ray) - 10;
	if (ray->side == 0)
		ttex->wall_x = ray->pl_y + ray->prep_wall_dist * ray->ray_dir_y;
	else
		ttex->wall_x = ray->pl_x + ray->prep_wall_dist * ray->ray_dir_x;
	ttex->wall_x -= floor(ttex->wall_x);
}

static int	ft_get_texture(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->ray_dir_y < 0)
			return (TEXTURE_NO);
		else
			return (TEXTURE_SO);
	}
	else
	{
		if (ray->ray_dir_x < 0)
			return (TEXTURE_WE);
		else
			return (TEXTURE_EA);
	}
}

void	coordinate_tex(t_game *game, t_ray *ray, int x)
{
	t_ray_tex		*ttex;
	double			step;
	unsigned int	color;
	int				y;

	ttex = &(ray->tex);
	set_coor_tex_var(ttex, &step, ray);
	y = ttex->draw_start;
	while (y < ttex->draw_end)
	{
		ttex->tex_y = (int)ttex->tex_pos & (TEX_HEIGHT - 1);
		ttex->tex_pos += step;
		color = game->tex[ttex->tex_idx] \
				.tex_data[TEX_HEIGHT * (int)ttex->tex_y + (int)ttex->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		ttex->re_map[y][x] = color;
		y++;
	}
}

static void	set_coor_tex_var(t_ray_tex *ttex, double *step, t_ray *ray)
{
	ttex->tex_x = (int)(ttex->wall_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0) \
			|| (ray->side == 1 && ray->ray_dir_y < 0))
	{
		ttex->tex_x = TEX_WIDTH - ttex->tex_x - 1;
	}
	*step = 1.0 * TEX_HEIGHT / ttex->line_height;
	ttex->tex_pos = (ttex->draw_start - ray->win_y / 2 \
						+ ttex->line_height / 2) * (*step);
}
