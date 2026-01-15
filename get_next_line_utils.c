/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:58:08 by igerasim          #+#    #+#             */
/*   Updated: 2026/01/15 01:42:19 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Moves 'n' bytes from 'src' to 'dest'
/// @return dest pointer
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

/// @brief Scans the first 'n' bytes of memory area 's' for the character 'c'
/// @return Pointer to matching byte or NULL
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/// @brief Frees the stash buffer and resets all variables (len, cap) to 0/NULL
/// @return Always returns NULL (useful for return statements)
char	*ft_nuke_stash(t_gnl *stash)
{
	if (stash->buf)
		free(stash->buf);
	stash->buf = NULL;
	stash->len = 0;
	stash->cap = 0;
	return (NULL);
}

/// @brief Frees a temporary buffer and returns a specific integer value
/// @return The value of 'ret_val', either -1 or 0
int	ft_free_ret(char *tmp, int ret_val)
{
	free(tmp);
	return (ret_val);
}

/// @brief Appends 'r' bytes from 'tmp' to stash, growing capacity geometrically
/// @return 1 on success, 0 on failure
int	ft_append_stash(t_gnl *stash, char *tmp, int r)
{
	char	*new_buf;
	size_t	new_cap;

	if (!stash->buf || stash->len + r > stash->cap)
	{
		new_cap = stash->cap * 2;
		if (stash->cap == 0)
			new_cap = BUFFER_SIZE;
		while (new_cap < stash->len + r)
			new_cap *= 2;
		new_buf = malloc(new_cap);
		if (!new_buf)
			return (0);
		if (stash->buf)
		{
			ft_memmove(new_buf, stash->buf, stash->len);
			free(stash->buf);
		}
		stash->buf = new_buf;
		stash->cap = new_cap;
	}
	ft_memmove(stash->buf + stash->len, tmp, r);
	stash->len += r;
	return (1);
}
