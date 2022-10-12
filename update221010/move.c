/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:25:55 by yukim             #+#    #+#             */
/*   Updated: 2022/10/12 21:10:23 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


static int move_space(t_game *game, double new_x, double new_y);

static int move_space(t_game *game, double new_x, double new_y)
{
    t_ray       *rray;

    rray = &(game->ray);
    if (!(0 <= (int)new_x && (int)new_x < game->map.max_width))
        return (FALSE);
    if (!(0 <= (int)new_y && (int)new_y < game->map.max_height))
        return (FALSE);
    if (game->map.maps[(int)(rray->pl_y)][(int)new_x] != '1')
        rray->pl_x = new_x;
    if (game->map.maps[(int)new_y][(int)(rray->pl_x)] != '1')
        rray->pl_y = new_y;
    return (TRUE);
}

void    move_forward_or_backward(t_game *game)
{
    t_ray       *rray;
    double      new_x;
    double      new_y;

    rray = &(game->ray);
    new_x = rray->pl_x - rray->dir_x * rray->move_speed;
    new_y = rray->pl_y - rray->dir_y * rray->move_speed;
    game->key_flag.move_backward = FALSE;
    if (game->key_flag.move_forward == TRUE)
    {
        new_x = rray->pl_x + rray->dir_x * rray->move_speed;
        new_y = rray->pl_y + rray->dir_y * rray->move_speed;
        game->key_flag.move_forward = FALSE;
    }
    move_space(game, new_x, new_y);
}

void    move_left_or_right(t_game *game)
{
    t_ray       *rray;
    double      new_x;
    double      new_y;

    rray = &(game->ray);
    new_x = rray->pl_x + (rray->x_dir_x * rray->move_speed);
    new_y = rray->pl_y + (rray->x_dir_y * rray->move_speed);
    game->key_flag.move_left = FALSE;
    if (game->key_flag.move_right == TRUE)
    {
        new_x = rray->pl_x - (rray->x_dir_x * rray->move_speed);
        new_y = rray->pl_y - (rray->x_dir_y * rray->move_speed);
        game->key_flag.move_right = FALSE;
    }
    move_space(game, new_x, new_y);
}