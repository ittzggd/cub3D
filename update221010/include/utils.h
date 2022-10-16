/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:46:57 by hejang            #+#    #+#             */
/*   Updated: 2022/10/16 15:17:49 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// ft_str_func.c
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

// is_utils.c
int		is_wall(char c);
int		is_space(char c);
void	is_map_last(t_info *info);
void	is_valid_element_color(t_info *info);
void	is_valid_texture_color(t_info *info);

//utils.c
int		ft_filecmp(char *argv);
void	ft_error(char *error_msg);
int		ft_atoi(const char *nptr);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

//save_dir.c

void	dir_w(t_game *game, char dir);
void	dir_e(t_game *game, char dir);
void	dir_n(t_game *game, char dir);
void	dir_s(t_game *game, char dir);

#endif
