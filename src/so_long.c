/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:13:42 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/17 17:28:40 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	return (1);
}

int	check_file_extension(char *str)
{
	char	**file_name;
	int		len;

	file_name = ft_split(str, '.');
	len = ft_strlen(file_name[1]);
	if (len != 3 || (ft_strncmp("ber", file_name[1], 3) != 0))
	{
		free_arr(file_name);
		return (0);
	}
	free_arr(file_name);
	return (1);
}

void	validate_map(char **map)
{
	if (!is_rectangular(map))
		print_errors(map, "Map is not rectangular");
	if (!check_walls_x(map) || !check_walls_y(map))
		print_errors(map, "Map is not closed");
	if (!check_min_elements(map))
		print_errors(map, "Map does not contain all required elements");
	if (!check_valid_chars(map))
		print_errors(map, "Map contains invalid characters");
	if (!check_path(map))
		print_errors(map, "Map has not valid path");
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	**map;

	if (argc == 2)
	{
		if (!check_file_extension(argv[1]))
			print_errors(NULL, "INCORRECT FILE EXTENSION");
		map = load_map(argv[1]);
		game.count_moves = 1;
		game.map = map;
		validate_map(map);
		if (!init_mlx(&game))
			print_errors(map, "Error: mlx_init failed");
		if (!create_window(&game))
			print_errors(map, "Error: Creating window");
		load_sprites(&game);
		render_map(&game);
		mlx_key_hook(game.win.win, handle_key, &game);
		mlx_hook(game.win.win, 17, 0, close_game, &game);
		mlx_loop(game.mlx);
		free_arr(map);
	}
	else
		ft_putstr_fd("\033[1;31mINCORRECT ARGS\n\033[0m", 2);
}
