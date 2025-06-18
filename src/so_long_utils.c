/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:15:16 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/19 00:53:47 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_errors(char **map, char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_arr(map);
	exit(1);
}

void	free_images(t_game *game)
{
	if (game->sprites.collectionable)
		mlx_destroy_image(game->mlx, game->sprites.collectionable);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.exit_final)
		mlx_destroy_image(game->mlx, game->sprites.exit_final);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
	if (game->sprites.player_down)
		mlx_destroy_image(game->mlx, game->sprites.player_down);
	if (game->sprites.player_left)
		mlx_destroy_image(game->mlx, game->sprites.player_left);
	if (game->sprites.player_right)
		mlx_destroy_image(game->mlx, game->sprites.player_right);
	if (game->sprites.player_up)
		mlx_destroy_image(game->mlx, game->sprites.player_up);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
}

int	close_game(t_game *game)
{
	free_arr(game->map);
	free_images(game);
	mlx_destroy_window(game->mlx, game->win.win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
