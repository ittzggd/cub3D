/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definecub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:54:49 by hejang            #+#    #+#             */
/*   Updated: 2022/09/24 14:48:55 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINECUB3D_H
# define DEFINECUB3D_H

# include "./cub3d.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SPACE -2

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

}	t_info; //map 제외 .map 파일에 담긴 정보

typedef struct s_map
{
	char **maps;
	int max_width;
	int max_height;
	int	sp_x;
	int	sp_y;
} t_map;

typedef struct s_player
{
	int pl_x;
	int pl_y;
	int orientation;
} t_player;

enum	orientation
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