/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaubry <tiaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:05 by tiaubry           #+#    #+#             */
/*   Updated: 2024/11/20 16:32:50 by tiaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	int	i;

	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!line)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

int	main(void)
{
	int	fd = open("t.txt", O_RDONLY);
	
	printf("%s", get_next_line(fd));
}