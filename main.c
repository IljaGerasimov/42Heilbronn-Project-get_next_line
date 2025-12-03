/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:46:37 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/03 18:09:15 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*line;

	if (fd == -1)
	{
		printf("Failed to open!\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Read: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}

//int main(void)
//{
//    int fd1 = open("text_a.txt", O_RDONLY); // Das wird fd 3 sein
//    int fd2 = open("text_b.txt", O_RDONLY); // Das wird fd 4 sein

//    char *line1 = get_next_line(fd1); // Liest aus Datei A
//    char *line2 = get_next_line(fd2); // Liest aus Datei B
//    printf("Datei A: %s", line1);
//    printf("Datei B: %s", line2);

//	free(line1);
//	free(line2);
//	close(fd1);
//	close(fd2);
//	return (0);
//}