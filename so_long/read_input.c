/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:06:54 by zgahrama          #+#    #+#             */
/*   Updated: 2025/08/27 18:21:34 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_newline(char *line)
{
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (newline)
		*newline = '\0';
}
char	**read_input(void)
{
	char	*line;
	char	**map;
	int		i;
	int		map_size;
	int		fd;
	char	**tmp;

	i = 0;
	map_size = 128;
	map = malloc(sizeof(char *) * map_size);
	if (!map)
	{
		perror("map allocation error :D");
		exit(1);
	}
	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	while ((line = get_next_line(fd)))
	{	
		remove_newline(line);
		if (i >= map_size - 1)
		{
			map_size *= 2;
			tmp = realloc(map, sizeof(char *) * map_size);
			if (!tmp)
			{
				perror("Error reallocating map :D");
				exit(1);
			}
			map = tmp;
		}
		map[i++] = line;
	}
	map[i] = NULL;
	free(line);
	close(fd);
	return (map);
}
