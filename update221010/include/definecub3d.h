/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definecub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:54:49 by hejang            #+#    #+#             */
/*   Updated: 2022/10/10 17:05:04 by yukim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINECUB3D_H
# define DEFINECUB3D_H

# include "./cub3d.h"

# define TRUE				1
# define FALSE				0
# define ERROR				-1
# define SPACE				-2
# define TEX_WIDTH			512
# define TEX_HEIGHT			512

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_EXIT		17

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC			53
# define KEY_LEFT			123
# define KEY_RIGHT			124

# define FOV				60
# define TEXTURE_COUNT		4

typedef struct s_info
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];	
	int		height;
	int		width;
	char	*backup;

}	t_info;

typedef struct s_map
{
	char	**maps;
	int		max_width;
	int		max_height;
	int		sp_x;
	int		sp_y;
}	t_map;

typedef struct s_ray_tex
{
	int		**re_map;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_idx;
	double	wall_x;
	double	tex_x;
	double	tex_y;
	double	tex_pos;
}	t_ray_tex;

typedef struct s_fl_ray
{
	double	ray_dir_x0;
	double	ray_dir_y0;
	double	ray_dir_x1;
	double	ray_dir_y1;
	double	row_distance;
	double	floor_step_x;
	double	floor_step_y;
	double	floor_x;
	double	floor_y;
	int		cell_x;
	int		cell_y;
	int		ftex_x;
	int		ftex_y;
}	t_fl_ray;

typedef struct s_ray
{
	double		pl_x;
	double		pl_y;
	double		win_x;
	double		win_y;
	double		dir_x;
	double		dir_y;
	double		x_dir_x;
	double		x_dir_y;
	double		turn_speed;
	double		move_speed;
	double		camera_x;
	double		plane_x;
	double		plane_y;
	// double		ray_x;
	// double		ray_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		prep_wall_dist;
	int			step_x;
	int			step_y;
	// double		hit_x;
	// double		hit_y;
	int			side;
	
	t_ray_tex	tex;
	t_fl_ray	flo;
}	t_ray;


typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_texture
{
	int		*tex_data;
	double	tex_xpm_width;
	double	tex_xpm_height;
}	t_texture;

typedef struct s_key_action
{
	int		move_left;
	int		move_right;
	int		move_forward;
	int		move_backward;
	int		rotate_left;
	int		rotate_right;
}	t_key_action;

typedef struct s_game
{
	t_info			info;
	t_map			map;
	t_img			img;
	t_mlx			mlx;
	t_ray			ray;
	t_texture		tex[TEXTURE_COUNT];
	t_key_action	key_flag;
}	t_game;

enum	e_orientation
{
	N = 1,
	S,
	E,
	W,
};

enum e_text_type
{
	TEXTURE_NO = 10,
	TEXTURE_SO = 11,
	TEXTURE_WE = 12,
	TEXTURE_EA = 13,
	FLOOR = 20,
	CEILLING = 21,
	MAP_CHARACTER = 30
};

#endif
