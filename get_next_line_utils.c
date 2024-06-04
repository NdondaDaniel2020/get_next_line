/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:17:33 by nmatondo          #+#    #+#             */
/*   Updated: 2024/05/31 11:17:34 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_find_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		l1;
	int		l2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			join[i] = s1[i];
		else
			join[i] = s2[i - l1];
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line_str;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i = 0;
	line_str = (char *)malloc(sizeof(char) * (i + 1));
	while ((str[i] != '\n') && (str[i] != '\0'))
	{
		line_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line_str[i] = str[i];
		i++;
	}
	line_str[i] = '\0';
	return (line_str);
}

char	*ft_get_new_str(char *str)
{
	int		i;
	int		ix;
	char	*new_str;

	i = 0;
	ix = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
	if (str[i] == '\0')
		return (NULL);
	while (str[i + ix] != '\0')
		ix++;
	new_str = (char *)malloc(sizeof(char) * (ix + 1));
	if (!new_str)
		return (NULL);
	ix = 0;
	while (str[i] != '\0')
	{
		new_str[ix] = str[i];
		i++;
		ix++;
	}
	free(str);
	new_str[i] = '\0';
	return (new_str);
}
