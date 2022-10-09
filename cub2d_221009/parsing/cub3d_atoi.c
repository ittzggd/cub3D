/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:33:01 by yukim             #+#    #+#             */
/*   Updated: 2022/09/24 18:23:34 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;

	if (!nptr || !(*nptr))
		return (ERROR);
	result = 0;
	i = 0;
	ft_skip(nptr, &i);
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (is_space(nptr[i]) == TRUE)
		return (SPACE);
	else if (nptr[i] != '\0' && nptr[i] != '\n')
		return (ERROR);
	if (result > 255)
		return (ERROR);
	return ((int)result);
}