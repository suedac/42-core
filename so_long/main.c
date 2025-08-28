#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

// Prototypes
char	**read_input(void);
int		rectangular(char **grid);
int		check_walls(char **grid);
int		map_checker(void);

int	main(void)
{
	void *mlx;
	void *win;
	void *img_floor;
    void *wall_up;
    void *wall_down;
    void *jaws_plant;
    void *bones;
	int w;
	int h;

    w = 32;
    h = 32;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "so_long");

	img_floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &w, &h);
	if (!img_floor)
	{
		printf("Failed to load wall.xpm\n");
		return (1);
	}

	// Draw image at position (100, 100)
	mlx_put_image_to_window(mlx, win, img_floor, 100, 100);

	mlx_loop(mlx);
	return (0);
}