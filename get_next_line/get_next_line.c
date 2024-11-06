/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaubry <tiaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:05 by tiaubry           #+#    #+#             */
/*   Updated: 2024/11/06 13:19:22 by tiaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
# endif

int	find_new_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	max_copy;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	max_copy = size - dest_len - 1;
	i = 0;
	if (dest_len >= size)
		return (size + src_len);
	while (src[i] && i < max_copy)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 2];
	char		*line;
	int		len;

	
	read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE + 2] = '\0';
	line = malloc(4096);
	if (*line == NULL)
		return (NULL);
	line = buffer;
	while (find_new_line(buffer))
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE + 1] = '\0';
		ft_strlcat(line, buffer, (ft_strlen(line) + BUFFER_SIZE));
	}
	return (line);
}

int	main()
{
	int	fichier = open("t.txt", O_RDONLY);
	char *line = get_next_line(fichier);
	printf("%s", line);
	free(line);
	return (0);
}
