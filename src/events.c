/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:39:00 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/19 00:25:16 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_player_position(t_game *game, int new_y, int new_x)
{
	game->map[game->pos_player.y][game->pos_player.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->pos_player.y = new_y;
	game->pos_player.x = new_x;
	ft_printf("Número de movimientos: %d\n", game->count_moves);
	game->count_moves++;
}

static void	apply_move(t_game *game, int new_y, int new_x)
{
	int	total_c;

	total_c = get_num_c(game->map);
	if (game->map[new_y][new_x] == '1')
		return ;
	else if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->count_c++;
			if (game->count_c == total_c)
				game->sprites.exit_current = game->sprites.exit_final;
		}
		update_player_position(game, new_y, new_x);
	}
	else if (game->map[new_y][new_x] == 'E')
	{
		if (game->count_c == total_c)
		{
			ft_printf("Número de movimientos: %d\n", game->count_moves);
			game->count_moves++;
			close_game(game);
		}
	}
}

static void	manage_direction(int dir, t_game *game, int new_y, int new_x)
{
	if (dir == 0)
	{
		game->sprites.player_current = game->sprites.player_up;
		new_y -= 1;
		apply_move(game, new_y, new_x);
	}
	else if (dir == 1)
	{
		game->sprites.player_current = game->sprites.player_right;
		new_x += 1;
		apply_move(game, new_y, new_x);
	}
	else if (dir == 2)
	{
		game->sprites.player_current = game->sprites.player_down;
		new_y += 1;
		apply_move(game, new_y, new_x);
	}
	else if (dir == 3)
	{
		game->sprites.player_current = game->sprites.player_left;
		new_x -= 1;
		apply_move(game, new_y, new_x);
	}
}

static void	move_player(t_game *game, int dir)
{
	int		new_x;
	int		new_y;

	game->count_c = 0;
	get_pos_player(game->map, &game->pos_player);
	new_x = game->pos_player.x;
	new_y = game->pos_player.y;
	manage_direction(dir, game, new_y, new_x);
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
