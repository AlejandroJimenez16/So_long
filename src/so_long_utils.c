/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:15:16 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/17 16:13:11 by alejandj         ###   ########.fr       */
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

void	free_queue(t_queue *queue)
{
	t_list	*current;
	t_list	*next;

	if (!queue)
		return ;
	current = queue->head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	free(queue);
}

void	print_errors(char **map, char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_arr(map);
	exit(1);
}

int	close_game(t_game *game)
{
	free_arr(game->map);
	mlx_destroy_window(game->mlx, game->win.win);
	exit(0);
}
