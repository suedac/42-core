/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:54:13 by zgahrama          #+#    #+#             */
/*   Updated: 2025/09/01 13:31:12 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include "git_libft/libft.h"

typedef struct s_map{
    char ** grid;
    int width;
    int height;
    int collectibles;
    int exit;
    int spawn_point;
}t_map;

char **read_input(void);
int rectangular(char **grid);
int get_map_width(char **grid);
int get_map_height(char **grid);
void remove_newline(char *line);
int	check_walls(char **grid);
int	check_points(char **grid);
int draw_map(void *win, void *mlx, t_map map);

#endif
