/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:48:13 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/13 13:41:15 by zgahrama         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*concatenated;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	concatenated = malloc(lens1 + lens2 + 1);
	if (!concatenated)
		return (0);
	i = 0;
	while (i < lens1)
	{
		concatenated[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		concatenated[i] = s2[i - lens1];
		i++;
	}
	concatenated[i] = '\0';
	return (concatenated);
}

char	*prepare_leftover(int fd, char **leftover)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!*leftover)
	{
		*leftover = init_leftover(*leftover, buffer);
		if (!*leftover)
		{
			free(buffer);
			return (NULL);
		}
	}
	*leftover = read_and_append(fd, *leftover, buffer);
	free(buffer);
	return (*leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!prepare_leftover(fd, &leftover) || !leftover || leftover[0] == '\0')
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	line = extract_line(leftover);
	leftover = update_leftover(leftover);
	return (line);
}
