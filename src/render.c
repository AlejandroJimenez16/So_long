/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:32:36 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/17 11:52:21 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_sprites(t_game *game, int w, int h)
{
	game->sprites.player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/pikachu_up.xpm", &w, &h);
	if (!game->sprites.player_up)
		print_errors(game->map, "Error load pikachu_up.xpm");
	game->sprites.player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/pikachu_down.xpm", &w, &h);
	if (!game->sprites.player_down)
		print_errors(game->map, "Error load pikachu_down.xpm");
	game->sprites.player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/pikachu_left.xpm", &w, &h);
	if (!game->sprites.player_left)
		print_errors(game->map, "Error load pikachu_left.xpm");
	game->sprites.player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/pikachu_right.xpm", &w, &h);
	if (!game->sprites.player_right)
		print_errors(game->map, "Error load pikachu_right.xpm");
	game->sprites.player_current = game->sprites.player_down;
}

void	load_sprites(t_game *game)
{
	int	h;
	int	w;

	game->sprites.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	if (!game->sprites.wall)
		print_errors(game->map, "Error load wall.xpm");
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	if (!game->sprites.floor)
		print_errors(game->map, "Error load floor.xpm");
	load_player_sprites(game, w, h);
	game->sprites.collectionable = mlx_xpm_file_to_image(game->mlx,
			"textures/pokeball.xpm", &w, &h);
	if (!game->sprites.collectionable)
		print_errors(game->map, "Error load pokeball.xpm");
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->sprites.exit)
		print_errors(game->map, "Error load exit.xpm");
}

void	draw_elements(char c, t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win.win, game->sprites.floor,
				j * TILE_SIZE, i * TILE_SIZE);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win.win, game->sprites.wall,
			j * TILE_SIZE, i * TILE_SIZE);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->sprites.player_current, j * TILE_SIZE, i * TILE_SIZE);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->sprites.collectionable, j * TILE_SIZE,
			i * TILE_SIZE);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->sprites.exit, j * TILE_SIZE, i * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	int		map_lines;
	char	c;

	i = 0;
	map_lines = count_lines_map(game->map);
	while (i < map_lines)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			c = game->map[i][j];
			draw_elements(c, game, i, j);
			j++;
		}
		i++;
	}
}
