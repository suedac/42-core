/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:02:35 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/13 13:26:24 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	copy_until_newline(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

char	*extract_line(char *leftover)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	while (leftover[len] != '\n' && leftover[len] != '\0')
		len++;
	if (leftover[len] == '\n')
		line = malloc(len + 2);
	else
		line = malloc(len + 1);
	if (!line)
		return (0);
	i = copy_until_newline(line, leftover);
	if (leftover[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_leftover(char *leftover)
{
	int		len;
	char	*new_leftover;
	int		i;

	i = 0;
	len = 0;
	while (leftover[len] != '\n' && leftover[len] != '\0')
		len++;
	if (leftover[len] == '\0')
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = malloc(ft_strlen(leftover + len + 1) + 1);
	if (!new_leftover)
	{
		free(leftover);
		return (NULL);
	}
	len++;
	while (leftover[len])
		new_leftover[i++] = leftover[len++];
	new_leftover[i] = '\0';
	free(leftover);
	return (new_leftover);
}
