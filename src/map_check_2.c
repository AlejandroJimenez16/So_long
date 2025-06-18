/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:45:26 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/18 19:52:56 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_valid_chars(char **map)
{
	int	i;
	int	j;
	int	map_lines;

	map_lines = count_lines_map(map) - 1;
	i = 0;
	while (i < map_lines)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '\n')
			{
				j++;
				continue ;
			}
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	flood_fill(char **copy, int x, int y)
{
	if (copy[y][x] == '1' || copy[y][x] == 'v')
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = 'v';
		return ;
	}
	if (copy[y][x] == '0' || copy[y][x] == 'C' || copy[y][x] == 'P')
		copy[y][x] = 'v';
	flood_fill(copy, x - 1, y);
	flood_fill(copy, x, y - 1);
	flood_fill(copy, x + 1, y);
	flood_fill(copy, x, y + 1);
}

static int	compare_maps(char **map, char **copy)
{
	int	i;
	int	j;
	int	map_lines;

	i = 0;
	map_lines = count_lines_map(map);
	while (i < map_lines)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' && copy[i][j] != 'v')
				return (0);
			if (map[i][j] == 'E' && copy[i][j] != 'v')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(char **map)
{
	t_pos	pos_player;
	char	**copy;

	get_pos_player(map, &pos_player);
	copy = duplicate_map(map);
	flood_fill(copy, pos_player.x, pos_player.y);
	if (!compare_maps(map, copy))
	{
		free_arr(copy);
		return (0);
	}
	free_arr(copy);
	return (1);
}
