/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:59:47 by nmatondo          #+#    #+#             */
/*   Updated: 2024/06/06 08:32:48 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_read_str(int fd, char *str);
char	*ft_find_char(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_new_str(char *str);
char	*ft_get_line(char *str);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);

#endif
