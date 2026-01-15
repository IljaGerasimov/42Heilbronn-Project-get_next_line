/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:52:58 by igerasim          #+#    #+#             */
/*   Updated: 2026/01/15 01:52:02 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	stash_read(int fd, t_gnl *stash)
{
	char	*tmp;
	int		r;

	tmp = malloc(BUFFER_SIZE);
	if (!tmp)
		return (-1);
	if (stash->buf && ft_memchr(stash->buf, '\n', stash->len))
		return (ft_free_ret(tmp, 0));
	r = 1;
	while (r > 0)
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == -1)
			return (ft_free_ret(tmp, -1));
		if (r == 0)
			break ;
		if (!ft_append_stash(stash, tmp, r))
			return (ft_free_ret(tmp, -1));
		if (ft_memchr(stash->buf, '\n', stash->len))
			break ;
	}
	free(tmp);
	return (0);
}

static char	*next_line_gotten(t_gnl *stash)
{
	char	*the_line;
	char	*nl_pos;
	size_t	l_len;

	if (!stash->buf || !stash->len)
		return (NULL);
	nl_pos = ft_memchr(stash->buf, '\n', stash->len);
	l_len = stash->len;
	if (nl_pos)
		l_len = (nl_pos - stash->buf) + 1;
	the_line = malloc(l_len + 1);
	if (!the_line)
		return (ft_nuke_stash(stash));
	ft_memmove(the_line, stash->buf, l_len);
	the_line[l_len] = '\0';
	if (nl_pos && stash->len > l_len)
	{
		stash->len -= l_len;
		ft_memmove(stash->buf, stash->buf + l_len, stash->len);
	}
	else
		ft_nuke_stash(stash);
	return (the_line);
}

char	*get_next_line(int fd)
{
	static t_gnl	stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash_read(fd, &stash) < 0 || stash.len == 0)
		return (ft_nuke_stash(&stash));
	return (next_line_gotten(&stash));
}
