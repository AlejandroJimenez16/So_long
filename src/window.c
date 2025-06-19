/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:07:29 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/19 03:12:28 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_window(t_game *game)
{
	game->win.rows = count_lines_map(game->map);
	game->win.cols = ft_strlen(game->map[0]) - 1;
	game->win.win_width = 15 * TILE_SIZE;
	game->win.win_height = 10 * TILE_SIZE;
	game->win.win = mlx_new_window(
			game->mlx,
			game->win.win_width,
			game->win.win_height,
			"So_long"
			);
	if (!game->win.win)
		return (0);
	return (1);
}
