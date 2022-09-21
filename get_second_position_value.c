#include "cub3d.h"

#define TRUE	1
#define FALSE	0
#define ERROR	-1


char	*get_texture_filepath(char **line);
int		get_rgb_array(char **line, int *array);


static char	*get_second_info(char *str);
static char	*get_rgb_str(char **line);
static int	change_rgb_str_to_array(char *line, int *array);

static char *get_second_info(char *str)
{
	char	*second_info;

	// skip space
	while (*str && is_space(*str))
		str++;
	if (*str) // if not '\0'
	{
		second_info = ft_strdup(str);
		if (!second_info)
		{
			// error msg
			return (NULL);
		}
	}
	return (second_info);
}

// outside : if get_texture_filepath return NULL => ERROR
char *get_texture_filepath(char **line)
{
	char	*copy;
	char	*filepath;
	int		i;

	if (!*(line))
		return (NULL);
	copy = get_skipped_copy_line(line, 0);
	if (!copy)
		return (NULL);
	i = extract_first_info_textlen(copy);
	filepath = get_second_info(copy + i);
	free(copy);
	free(line);
	*line = NULL;
	return(filepath);
}

// outside : if get_color_array_value return ERROR => ERROR
int get_rgb_array(char **line, int *array)
{
	char	*rgb_str;
	int		i;
	int		res;

	if (!(*line))
		return (ERROR);
	rgb_str = get_rgb_str(line);
	res = ERROR;
	if (rgb_str)
	{
		res = change_rgb_str_to_array(line, array);
		free(rgb_str);
	}
	free(*line);
	*line = NULL;
	return (res);
}

static char *get_rgb_str(char **line)
{
	char	*copy;
	char	*rgb_str;
	int		i;

	if (!(*line))
		return (NULL);
	copy = get_skipped_copy_line(line, 0);
	if (!copy)
		return (NULL);
	i = extract_first_info_textlen(copy);
	rgb_str = get_second_info(copy + i);
	free(copy);
	return (rgb_str);
}














// outside : if get_color_array_value return ERROR => ERROR
static int change_rgb_str_to_array(char *rgb_str, int *array)
{
	int		i;
	int		res;
	char	*red = NULL;
	char	*green = NULL;
	char	*blue = NULL;

	res = ERROR;
	i = 0;
	while (*(rgb_str + i)) // if not empty str (! '\0')
	{
		i = i + extract_color_str(rgb_str + i, ',', red);
		i = i + extract_color_str(rgb_str + i, ',', green);
		i = i + extract_color_str(rgb_str + i, '\n', blue);

		if (*(rgb_str + i) == '\0') // if valid shape '23,50,40\n'
			res = 0;
		else // if invalid shape'23,50,40\0' || '23, abxaas23, 2\n'
			break ; // res = -1;
	}

	if (res == 0 && red && green && blue) // valid shape && ft_strdup(=malloc) is all OK
	{
		array[0] = ft_atoi(red);
		array[1] = ft_atoi(green);
		array[2] = ft_atoi(blue);
	}
	if ((is_valid_agb_range(array) == FALSE) || !red || !green || !blue) // invalid range or malloc failed
		res = ERROR;
	if (red)
		free(red);
	if (green)
		free(green);
	if (blue)
		free(blue);
	return(res);
}

static int is_valid_agb_range(int	*array)
{
	if (array[0] < 0 || array[1] < 0 || array[2] < 0)
		return FALSE;
	if (array[0] > 255 || array[1] > 255 || array[2] > 255)
		return FALSE;
	return TRUE;
}

static int	extract_color_str(char *tmp_line, char delimiter, char *color_str)
{
	int	i;

	i = 0;
	while ('0' <= tmp_line[i] && tmp_line[i] <= '9')
		i++;
	if (tmp_line[i] == delimiter)
	{
		tmp_line[i] = '\0';
		color_str = ft_strdup(tmp_line);
	}
	return (i + 1);
}