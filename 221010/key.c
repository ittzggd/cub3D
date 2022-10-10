/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:14:51 by yukim             #+#    #+#             */
/*   Updated: 2022/10/10 14:27:37 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	key_action(t_game *game)
{
	t_key_action	*kkey;

	kkey = &(game->key_flag);
	if (kkey->rotate_left || kkey->rotate_right)
		rotate_camera(game);
	else if (kkey->move_left || kkey->move_right)
		move_left_or_right(game);
	else if (kkey->move_forward || kkey->move_forward)
		move_forward_or_backward(game);
	else 
		return (FALSE);
	return (TRUE);
}

int	key_press(int keycode, t_game *game)
{
	t_key_action	*kkey;

	kkey = &(game->key_flag);
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_A)
		kkey->move_left = TRUE;
	else if (keycode == KEY_S)
		kkey->move_backward = TRUE;
	else if (keycode == KEY_D)
		kkey->move_right = TRUE;
	else if (keycode == KEY_W)
		kkey->move_forward = TRUE;
	else if (keycode == KEY_LEFT)
		kkey->rotate_left = TRUE;
	else if (keycode == KEY_RIGHT)
		kkey->rotate_right = TRUE;
	key_action(game);
	return (1);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit(0);
}

