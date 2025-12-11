/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:58:08 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/11 04:44:41 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Moves 'n' bytes from 'src' to 'dest'
/// @return dest pointer
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	}
	return (dest);
}

/// @brief Fills the first 'n' bytes of memory area 's' with byte 'c'
/// @param s string to overwrite
/// @return pointer to s
void	*ft_memset(void *s, int c, size_t n)
{
	if (!s)
		return (NULL);
	while (n--)
		((unsigned char *)s)[n] = (unsigned char)c;
	return (s);
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

/// @brief Allocates memory for an array of 'nmemb' elements of 'size' bytes
/// @return Pointer to the zeroed out memory block
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (size && nmemb > (SIZE_MAX / size))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

/// @brief Allocates a new buffer and copies data from old
/// @param ptr old buffer to be freed
/// @return Pointer to the new, resized buffer
void	*ft_mem_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = ft_calloc(1, new_size);
	if (!new_ptr)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (ptr && old_size)
	{
		if (old_size < new_size)
			ft_memmove(new_ptr, ptr, old_size);
		else
			ft_memmove(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}
