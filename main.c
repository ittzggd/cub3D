/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:26:09 by hejang            #+#    #+#             */
/*   Updated: 2022/09/20 04:43:31 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"
#include "./define.h"

int main(int argc, char **argv)
{	
	int	fd;
	t_info	info;

	check_argument(argc, argv);
	fd = open((argv[1], O_RDWR);
	if (fd < 0)
		ft_error("open file failed");
	read_map(fd, &info);
	init_map(argv[1]);
}

void	read_map(int fd, t_info *info)
{
	char	*tmp;
	char	*back_up;
	char	*f_color;
	char	*c_color;
	int		sp_cnt;

	back_up = ft_strdup("");
	sp_cnt = 0;
	info->north_texture = get_next_line(fd);
	info->south_texture = get_next_line(fd);
	info->west_texture = get_next_line(fd);
	info->east_texture = get_next_line(fd);
	f_color = get_next_line(fd);
	c_color = get_next_line(fd);

	tmp = get_next_line(fd);
	while(tmp)
	{
		sp_cnt += check_one_line_map(tmp);
		ft_strjoin(back_up, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	if(sp_cnt > 1)
		ft_error("too many start point");
}

int	check_one_line_map(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while(line[i] != '\0')
	{
		if(line[i] != '0' || line[i] != '1' || line[i] != 'N' || line[i] != '\n'
			|| line[i] != 'S' || line[i] != 'E' || line[i] != 'W' || line[i] != ' ')
			ft_error("The map must be composed of only 6 possible characters");
		if(line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			cnt++;
		i++;
	}
	return (cnt);
}

void	check_argument(int argc, char **argv)
{

	if(argc != 2)
	{
		printf("./cub3D [mapfile.map]");
		exit(1);
	}
	if(ft_filecmp(argv[1]) == FALSE)
	{
		printf("the argument needs to be a map in format *.cub");
		exit(1);
	}
}

int	ft_filecmp(char *argv)
{
	int	len;

	if(!argv)
		return (ERROR);
	len = 0;
	while(argv[len] != '\0')
		len++;
	return(ft_strncmp(&argv[len - 3], ".map", 4));
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && n > 0)
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
		n--;
	}
	if (n == 0 || (str1[i] == '\0' && str2[i] == '\0'))
		return (TRUE);
	else
		return (FALSE);
}
