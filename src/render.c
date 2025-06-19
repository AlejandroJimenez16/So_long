/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:32:36 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/19 03:37:55 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_player_sprites(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
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
	load_player_sprites(game);
	game->sprites.collectionable = mlx_xpm_file_to_image(game->mlx,
			"textures/pokeball.xpm", &w, &h);
	if (!game->sprites.collectionable)
		print_errors(game->map, "Error load pokeball.xpm");
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->sprites.exit)
		print_errors(game->map, "Error load exit.xpm");
	game->sprites.exit_final = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_final.xpm", &w, &h);
	if (!game->sprites.exit_final)
		print_errors(game->map, "Error load exit_final.xpm");
	game->sprites.exit_current = game->sprites.exit;
}

static void	draw_elements(char c, t_game *game, int i, int j)
{
	if (c == '0')
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
			game->sprites.exit_current, j * TILE_SIZE, i * TILE_SIZE);
}

static void	update_camera(t_game *game)
{
	int	visible_cols;
	int	visible_rows;

	visible_cols = game->win.win_width / TILE_SIZE;
	visible_rows = game->win.win_height / TILE_SIZE;
	game->camera_x = game->pos_player.x - visible_cols / 2;
	game->camera_y = game->pos_player.y - visible_rows / 2;
	if (game->camera_x < 0)
		game->camera_x = 0;
	if (game->camera_y < 0)
		game->camera_y = 0;
	if (game->camera_x > game->win.cols - visible_cols)
		game->camera_x = game->win.cols - visible_cols;
	if (game->camera_y > game->win.rows - visible_rows)
		game->camera_y = game->win.rows - visible_rows;
	if (game->camera_x < 0)
		game->camera_x = 0;
	if (game->camera_y < 0)
		game->camera_y = 0;
}

void	render_map(t_game *game)
{
	int			i;
	int			j;
	t_camera	cam;
	int			map_cols;

	update_camera(game);
	map_cols = ft_strlen(game->map[0]) - 1;
	cam.visible_rows = game->win.win_height / TILE_SIZE;
	cam.visible_cols = game->win.win_width / TILE_SIZE;
	i = -1;
	while (++i < cam.visible_rows)
	{
		cam.map_i = game->camera_y + i;
		if (cam.map_i >= count_lines_map(game->map))
			break ;
		j = -1;
		while (++j < cam.visible_cols)
		{
			cam.map_j = game->camera_x + j;
			if (cam.map_j >= map_cols)
				break ;
			draw_elements(game->map[cam.map_i][cam.map_j], game, i, j);
		}
	}
}
