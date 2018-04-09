/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:09:43 by acalleja          #+#    #+#             */
/*   Updated: 2018/03/23 01:20:22 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef struct	s_fd
{
	char			*cpy;
	int				fd;
	struct s_fd		*next;
	char			*begin;
}				t_fd;
int				get_next_line(const int fd, char **line);

#endif
