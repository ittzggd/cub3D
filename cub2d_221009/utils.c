/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:38:08 by hejang            #+#    #+#             */
/*   Updated: 2022/09/24 17:37:29 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


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

int	ft_filecmp(char *argv)
{
	int	len;

	if(!argv)
		return (ERROR);
	len = 0;
	while(argv[len] != '\0')
		len++;
	return(ft_strncmp(&argv[len -4], ".cub", 4));
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*save;

	if (!s)
		return (NULL);
	save = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
		{
			save = (char *)s + i;
			return (save);
		}
		i++;
	}
	if ((char )c == '\0')
		save = (char *)s + i;
	return (save);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	if (s)
	{
		while (s[cnt] != '\0')
			cnt++;
	}
	return (cnt);
}


void	ft_error(char *error_msg)
{
	int	len;

	len = ft_strlen(error_msg);
	write(2, error_msg, len);
	exit(1);
}


char	*ft_strdup(char *s)
{
	char	*ptr;
	int		s_len;
	int		i;

	s_len = ft_strlen(s) + 1;
	ptr = (char *)malloc(sizeof(char) * s_len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new)
		return (NULL);
	while (i < (s1_len + s2_len))
	{
		if (i < s1_len)
			new[i] = *(s1 + i);
		else
			new[i] = *(s2 + i - s1_len);
		i++;
	}
	new[i] = '\0';
	return (new);
}
