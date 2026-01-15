/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:47:37 by igerasim          #+#    #+#             */
/*   Updated: 2026/01/15 01:09:33 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char	*buf;
	size_t	len;
	size_t	cap;
}			t_gnl;

char		*get_next_line(int fd);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_append_stash(t_gnl *stash, char *tmp, int r);
int			ft_free_ret(char *tmp, int ret_val);
char		*ft_nuke_stash(t_gnl *stash);

#endif