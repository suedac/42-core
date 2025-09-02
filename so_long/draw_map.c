/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:54:08 by zgahrama          #+#    #+#             */
/*   Updated: 2025/09/02 14:09:15 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(void *win, void *mlx, t_map map)
{
	void	*img_floor;
	int		w;
	int		h;
	int		x;
	int		y;
	void	*wall_up;
	void	*e_tile;
	//void	*spawn_p;
	void	*player;

	w = 32;
	h = 32;
	y = 0;
	e_tile = mlx_xpm_file_to_image(mlx, "textures/e_tile.xpm", &w, &h);
	img_floor = mlx_xpm_file_to_image(mlx, "textures/0_tile.xpm", &w, &h);
	wall_up = mlx_xpm_file_to_image(mlx, "textures/1_wall.xpm", &w, &h);
	//spawn_p = mlx_xpm_file_to_image(mlx, "textures/spawn_p.xpm", &w, &h);
	player = mlx_xpm_file_to_image(mlx, "textures/player_fixed2.xpm", &w, &h);
	if (!img_floor)
	{
		printf("Failed to load wall.xpm\n");
		return (0);
	}
	while (map.grid[y])
	{
		x = 0;
		while (map.grid[y][x])
		{
			mlx_put_image_to_window(mlx, win, img_floor, x * 32, y * 32);
			if (map.grid[y][x] == '1')
				mlx_put_image_to_window(mlx, win, wall_up, x * 32, y * 32);
			if (map.grid[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, e_tile, x * 32, y * 32);
			if (map.grid[y][x] == 'P')
			{
				//mlx_put_image_to_window(mlx, win, spawn_p, x * 32, y * 32);
				mlx_put_image_to_window(mlx, win, player, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
	printf("Loaded image size: %d x %d\n", w, h);
	return (1);
}
