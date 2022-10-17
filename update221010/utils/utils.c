/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:38:08 by hejang            #+#    #+#             */
/*   Updated: 2022/10/17 11:35:11 by yukim            ###   ########seoul.kr  */
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
	while (is_space(nptr[i]) == TRUE)
		i++;
	if (nptr[i] != '\0' && nptr[i] != '\n')
		return (ERROR);
	if (result > 255)
		return (ERROR);
	return ((int)result);
}

int	ft_filecmp(char *argv)
{
	int	len;

	if (!argv)
		return (ERROR);
	len = 0;
	while (argv[len] != '\0')
		len++;
	return (ft_strncmp(&argv[len -4], ".cub", 4));
}

void	ft_error(char *error_msg)
{
	int	len;

	len = ft_strlen(error_msg);
	write(2, error_msg, len);
	exit(1);
}
