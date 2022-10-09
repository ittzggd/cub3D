/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukim <yukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:54:28 by yukim             #+#    #+#             */
/*   Updated: 2022/02/12 02:54:28 by yukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

char	*read_file(char *backup, int fd)
{
	ssize_t	read_return;
	char	*buf;
	char	*ptr;

	if (backup && ft_strchr(backup, '\n'))
		return (backup);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_return = read(fd, buf, BUFFER_SIZE);
	while (read_return > 0)
	{
		buf[read_return] = '\0';
		ptr = ft_strjoin(backup, buf);
		free(backup);
		backup = ptr;
		if (!ptr || (ft_strchr(backup, '\n')))
			break ;
		read_return = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (read_return < 0)
		return (NULL);
	return (backup);
}

char	*extract_line(char *backup)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (backup[len] && backup[len] != '\n')
		len++;
	if (backup[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = backup[i];
		i++;
	}	
	line[i] = '\0';
	return (line);
}

char	*reload_backup(char *backup, char *line)
{
	char	*new;

	if (backup && !(line))
	{
		free(backup);
		backup = NULL;
	}
	if (!line)
		return (NULL);
	new = ft_strdup(backup + ft_strlen(line));
	free(backup);
	backup = new;
	if (!new)
	{
		free(line);
		line = NULL;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	backup = read_file(backup, fd);
	if (!backup)
		return (NULL);
	else if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	line = extract_line(backup);
	backup = reload_backup(backup, line);
	if (!backup)
		return (NULL);
	return (line);
}
