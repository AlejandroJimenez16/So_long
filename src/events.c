/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:39:00 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/17 02:57:59 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	apply_move(t_game *game, int new_y, int new_x, int count_c)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	else if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		if (game->map[new_y][new_x] == 'C')
            count_c++;
		game->map[game->pos_player.y][game->pos_player.x] = '0';
		game->map[new_y][new_x] = 'P';
		game->pos_player.y = new_y;
		game->pos_player.x = new_x;
	}
	// HACER SI ES E
}
void	move_player(t_game *game, int dir)
{
	int		new_x;
	int		new_y;
	int		count_c;

	count_c = 0;
	get_pos_player(game->map, &game->pos_player);
	new_x = game->pos_player.x;
	new_y = game->pos_player.y;
	if (dir == 0)
	{
		game->sprites.player_current = game->sprites.player_up;
		new_y -= 1;
		apply_move(game, new_y, new_x, count_c);
	}
	else if (dir == 1)
	{
		game->sprites.player_current = game->sprites.player_right;
		new_x+=1;
		apply_move(game, new_y, new_x, count_c);
	}
	else if (dir == 2)
	{
		game->sprites.player_current = game->sprites.player_down;
		new_y+=1;
		apply_move(game, new_y, new_x, count_c);
	}
	else if (dir == 3)
	{
		game->sprites.player_current = game->sprites.player_left;
		new_x-=1;
		apply_move(game, new_y, new_x, count_c);
	}
}

int	close_game(t_game *game)
{
	free_arr(game->map);
	mlx_destroy_window(game->mlx, game->win.win);
	exit(0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 1);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 2);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, 3);
	mlx_clear_window(game->mlx, game->win.win);
	render_map(game);
	return (0);
}
