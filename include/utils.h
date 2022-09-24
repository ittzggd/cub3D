/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:46:57 by hejang            #+#    #+#             */
/*   Updated: 2022/09/24 17:23:46 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_filecmp(char *argv);
char	*ft_strchr(const char *s, int c);
int		ft_skip(const char *str, int *i);
void	ft_error(char *error_msg);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

// is_utils.c
int		is_space(char c);
void	is_map_last(t_info *info);
void	is_valid_element_color(t_info *info);

// second_pos_info_utils.c
char	*get_second_info(char *str);
char	*get_rgb_str(char **line);
int		change_rgb_str_to_array(char *line, int *array, int *res);


#endif
