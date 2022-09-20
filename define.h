/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:54:49 by hejang            #+#    #+#             */
/*   Updated: 2022/09/20 02:00:00 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
#define DEFINE_H

#include "./cub3d.h"

typedef struct s_info
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];	

}	t_info; //map 제외 .map 파일에 담긴 정보

typedef struct s_map
{
	char **maps;
	int max_width;
	int max_height;
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

# define TRUE 1
# define FALSE 0
# define ERROR -1

#endif