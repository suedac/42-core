/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:16:51 by zgahrama          #+#    #+#             */
/*   Updated: 2025/08/28 14:39:21 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char **grid)
{
	if (!grid || !grid[0])
		return (0);
	return (int)ft_strlen(grid[0]);
}

int	get_map_height(char **grid)
{
	int	height;

	height = 0;
	if (!grid)
		return (0);
	while (grid[height])
		height++;
	return (height);
}

int	rectangular(char **grid)
{
	int	i;
	int	j;
	int	width;

	width = get_map_width(grid);
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
			j++;
		if ((int)ft_strlen(grid[i]) != width)
		{
			perror("this potato is too big ୧(๑•̀ᗝ•́)૭");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **grid)
{
	int	i;
	int	height;
	int	width;

	height = get_map_height(grid);
	width = get_map_width(grid);
	i = 0;
	while (i < width)
	{
		if (grid[0][i] != '1' || grid[height - 1][i] != '1')
		{
			perror("bruh, this map fr?!(ꐦ¬_¬)");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (grid[i][0] != '1' || grid[i][width - 1] != '1')
		{
			perror("bruh, this map fr?!(ꐦ¬_¬)");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_points(char **grid)
{
	int	i;
	int	j;
	int	flag[3] = {0, 0, 0};//you will need to change this T_T

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'P')
				flag[0]++;
			if (grid[i][j] == 'E')
				flag[1]++;
			if (grid[i][j] == 'C')
				flag[2]++;
			j++;
		}
		i++;
	}
	if (flag[0] != 1 || flag[1] != 1 || flag[2] < 1)
	{
		perror("RTFM!!!!!ヽ( `д´*)ノ");
		return (0);
	}
	return (1);
}

int	map_checker(void)
{
	t_map *my_map = malloc(sizeof(t_map));
	my_map->grid = read_input();
	if(rectangular(my_map->grid) == 1 && check_walls(my_map->grid) == 1 && check_points(my_map->grid) == 1)
		return 1;
	perror("i hate your map so i will not run this game╭∩╮( •̀_•́ )╭∩╮");
	return (0);
}