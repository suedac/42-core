/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:48:13 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/12 17:19:16 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init_leftover(char *leftover, char *buffer)
{
	leftover = malloc(1);
	if (!leftover)
	{
		free(buffer);
		return (NULL);
	}
	leftover[0] = '\0';
	return (leftover);
}

char	*read_and_append(int fd, char *leftover, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (!ft_strchr(leftover, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			tmp = leftover;
			leftover = ft_strjoin(leftover, buffer);
			free(tmp);
		}
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	if (!leftover)
	{
		leftover = init_leftover(leftover, buffer);
		if (!leftover)
			return (0);
	}
	leftover = read_and_append(fd, leftover, buffer);
	free(buffer);
	if (!leftover || leftover[0] == '\0')
		return (0);
	line = extract_line(leftover);
	leftover = update_leftover(leftover);
	return (line);
}
