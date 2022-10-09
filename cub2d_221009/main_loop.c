/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:30:45 by yukim             #+#    #+#             */
/*   Updated: 2022/10/08 19:30:45 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	main_loop_ray(t_game *game);

int	main_loop_ray(t_game *game)
{
	int		is_update;

	is_update = key_action(game);
	if (is_update == TRUE)
	{
		raycast(game);
		draw(game)
	}
	return (0);
}