#include "cub3d.h"

char	*get_skipped_copy_line(char **line, int fd);
void	skip_new_line(char *line, int fd);
char	*skip_start_space(char **line, int fd);

char *get_skipped_copy_line(char **line, int fd)
{
	char	*copy;

	if (*line)
		skip_new_line(line, fd);
	if (!(*line))
		return (NULL);

	copy = skip_start_space(line, fd);
	if (!copy)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	return (copy);
}


void skip_new_line(char **line, int fd)
{
	if (!(*line))
		return (NULL); // ERROR
	while (ft_strncmp("\n", *line, -1) == 0)
	{
		free(*line);
		*line = get_next_line(fd);
		if (!(*line))
			return ; // EOF
	}
}

// pass space   ex) "             No    ./texture", "      11111111111"
char *skip_start_space(char **line, int fd)
{
	int		i;
	char	*copy;

	if (!(*line))
		return (NULL);
	i = 0;
	while ((*line)[i] && is_space((*line)[i]))
		i++;
	
	// ex) "                     " 
	if ((*line)[i] == '\0' && fd > 0)
	{
		free(*line);
		*line = get_next_line(fd);
		if (!(*line)) 
			return (NULL);  // EOF or Error
		get_text_type(line, fd);
	}
	copy = ft_strdup((*line)[i]);
	if (!copy)
	{
		// error msg 
		return (NULL);
	}
	return (copy);
}

