/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:54:49 by hejang            #+#    #+#             */
/*   Updated: 2022/09/19 21:56:05 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
#define DEFINE_H

typedef struct s_map
{
	char maps**;
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

#endif