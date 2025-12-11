/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:52:58 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/11 08:32:49 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	read_to_stash(int fd, t_gnl *stash)
{
	char	*line;
}

static char	*extract_line(t_gnl *stash);

char	*get_next_line(int fd)
{
	static t_gnl	stash[FD_MAX];

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_to_stash(fd, &stash[fd]) == 0 && stash[fd].len == 0)
	{
		if (stash[fd].buf)
		{
			free(stash[fd].buf);
			stash[fd].buf = NULL;
			stash[fd].len = 0;
		}
		return (NULL);
	}
	return (extract_line(&stash[fd]));
}

// Funktion get_next_line(fd):
//    Statische Variable: stash[FD_MAX]

//    1. LESE-PHASE (Loop):
//      Solange kein \n im stash ist UND wir nicht am Ende der Datei sind:
//      a) Erstelle temporären Buffer.
//      b) Lies read(fd, buffer, BUFFER_SIZE).
//      c) Wenn read 0 gibt (EOF) -> Hör auf zu lesen.
//		d) Vereinige stash + buffer (Hier brauchen wir doch einen Join,
//		weil stash wachsen muss).
//      e) Free den alten stash.

//    2. EXTRAKTIONS-PHASE (Die Zeile holen):
//       Wenn im stash nichts drin ist -> Return NULL.
//       Suche das \n.
//       Kopiere alles von 0 bis \n in einen neuen String "line".

//    3. CLEANUP-PHASE (Das memmove Prinzip):
//       Alles NACH dem \n ist der "Rest".
//       Erstelle einen neuen stash, der nur den Rest enthält.
//       (Oder verschiebe die Bytes,
//		wenn wir denselben Pointer behalten wollen).
//       Free den alten Kram.

//    4. Return "line".