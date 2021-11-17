/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:25:53 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/12 18:21:32 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# define BUFFER_SIZE 42

typedef struct s_read
{
	int				index;
	int				check;
	int				read_ret;
	char			*reading;
	char			*line;
}					t_read;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char		*ft_strdup(const char *s);
char		*ft_free(char *s);

#endif