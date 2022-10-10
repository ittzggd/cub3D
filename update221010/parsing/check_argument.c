/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:21:26 by yukim             #+#    #+#             */
/*   Updated: 2022/10/10 16:26:20 by yukim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_argument(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("./cub3D [mapfile.map]");
		exit(1);
	}
	if (ft_filecmp(argv[1]) == FALSE)
	{
		printf("the argument needs to be a map in format *.cub");
		exit(1);
	}
}
