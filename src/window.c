/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:07:29 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/17 17:32:09 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_window(t_game *game)
{
	game->win.rows = count_lines_map(game->map);
	game->win.cols = ft_strlen(game->map[0]) - 1;
	game->win.win_width = game->win.cols * TILE_SIZE;
	game->win.win_height = game->win.rows * TILE_SIZE;
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
