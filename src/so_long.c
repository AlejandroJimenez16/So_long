/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:13:42 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/19 12:31:48 by alejandj         ###   ########.fr       */
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

static int	file_exist(char *path)
{
	int	fd;

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int	check_file_extension(char *str)
{
	char	**file_name;
	char	**extension_part;
	int		i;
	int		j;

	file_name = ft_split(str, '.');
	if (!file_name || !file_name[0])
		return (0);
	i = 0;
	while (file_name[i])
		i++;
	i--;
	extension_part = ft_split(str, '/');
	if (!extension_part || !extension_part[0])
		return (0);
	j = 0;
	while (extension_part[j])
		j++;
	j--;
	if (ft_strlen(extension_part[j]) < 5)
		return (free_arr(file_name), free_arr(extension_part), 0);
	if (ft_strlen(file_name[i]) != 3 || ft_strncmp(file_name[i], "ber", 3) != 0)
		return (free_arr(file_name), free_arr(extension_part), 0);
	return (free_arr(file_name), free_arr(extension_part), 1);
}

static void	validate_map(char **map)
{
	if (!is_rectangular(map))
		print_errors(map, "Map is not rectangular");
	if (!check_walls_x(map) || !check_walls_y(map))
		print_errors(map, "Map is not closed");
	if (!check_valid_chars(map))
		print_errors(map, "Map contains invalid characters");
	if (!check_min_elements(map))
		print_errors(map, "Map must contain exactly one P (player), "
			"one E (exit), and at least one C (collectible)");
	if (!check_path(map))
		print_errors(map, "Map has not valid path");
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		if (!file_exist(argv[1]))
			print_errors(NULL, "File does not exist");
		if (!check_file_extension(argv[1]))
			print_errors(NULL, "Incorrect file extension");
		game.map = load_map(argv[1]);
		if (!game.map)
			print_errors(NULL, "File is empty or error loading map");
		game.count_moves = 1;
		validate_map(game.map);
		if (!init_mlx(&game))
			print_errors(game.map, "mlx_init failed");
		if (!create_window(&game))
			print_errors(game.map, "Creating window");
		load_sprites(&game);
		render_map(&game);
		mlx_key_hook(game.win.win, handle_key, &game);
		mlx_hook(game.win.win, 17, 0, close_game, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_putstr_fd("\033[1;31mINCORRECT ARGS\n\033[0m", 2);
}
