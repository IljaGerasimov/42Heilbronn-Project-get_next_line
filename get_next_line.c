/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:52:58 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/11 04:44:22 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || fd > FD_MAX)
	{
	}
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