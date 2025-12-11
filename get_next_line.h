/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:58:03 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/11 04:43:27 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stddef.h>
# include <stdint.h>

typedef struct s_gnl
{
	char	*buf;
	size_t	len;
	size_t	buf_cap;
}			t_gnl;

char		*get_next_line(int fd);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_mem_realloc(void *ptr, size_t old_size, size_t new_size);

#endif