#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

// Prototypes
char	**read_input(void);
int		rectangular(char **grid);
int		check_walls(char **grid);
int		map_checker(void);
int		draw_map(void *win, void *mlx, t_map map);

int	main(void)
{
	void *mlx;
	void *win;
	t_map map;
	int TILE_SIZE = 32;

	map.grid = read_input();
	int width = get_map_width(map.grid);
	int height = get_map_height(map.grid);
	int win_width = width * TILE_SIZE;
	int win_height = height * TILE_SIZE;
	mlx = mlx_init();
	win = mlx_new_window(mlx, win_width, win_height, "so_long");
	map.grid = read_input();

	draw_map(win, mlx, map);

	mlx_loop(mlx);
	return (0);
}