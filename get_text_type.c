#include "cub3d.h"

#define TRUE	1
#define FALSE	0
#define ERROR	-1


enum e_text_type
{
	TEXTURE_NO = 10,
	TEXTURE_SO = 11,
	TEXTURE_WE = 12,
	TEXTURE_EA = 13,
	FLOOR = 20,
	CEILLING = 21,
	MAP_CHARACTER = 30
};


int			get_text_type(char **line, int fd);
int			extract_first_info_textlen(char *line);
int			is_space(char c);

static int	is_type_identifier(char *skipped_copyline);
static int	is_type_map(char *skipped_copyline);



int	is_space(char c) // space character only whitespace? or need check more space character? 
{
	return (c == '\t' || c == ' ');
}


int get_text_type(char **line, int fd)
{
	char	*copy;
	int		type;


	copy = get_skipped_copy_line(line, fd);
	if (!copy)
		return (0);

	type = is_type_identifier(copy);
	if (type == FALSE)
		type = is_type_map(copy);
	// FREE
	// don't free line here
	// to get second info 
	free(copy);
	if (type == FALSE)
		return (ERROR);
	return (type);
}

int	extract_first_info_textlen(char *line)
{
	// pos = 1 == First Position
	int	len;

	len = 0;
	while (line[len] && is_space(line[len]) == FALSE)
		len++;
	return (len);
}

static int is_type_identifier(char *skipped_copyline)
{
	int	info_len;

	info_len = extract_first_info_textlen(skipped_copyline);
	if (ft_strncmp("NO", line, info_len) == 0)
		return (TEXTURE_NO);
	if (ft_strncmp("SO", line, info_len) == 0)
		return (TEXTURE_SO);
	if (ft_strncmp("WE", line, info_len) == 0)
		return (TEXTURE_WE);
	if (ft_strncmp("EA", line, info_len) == 0)
		return (TEXTURE_EA);
	if (ft_strncmp("F", line, info_len) == 0)
		return (FLOOR);
	if (ft_strncmp("C", line, info_len) == 0)
		return (CEILLING);
	return (FALSE);
}

static int	is_type_map(char *skipped_copyline)
{
	int	i;

	if (skipped_copyline[i] == '0' || skipped_copyline[i] == '1' || \
		skipped_copyline[i] == 'N' || skipped_copyline[i] == 'S' || \
		skipped_copyline[i] == 'E' || skipped_copyline[i] == 'W')
		return (MAP_CHARACTER);
	return (FALSE);
}
