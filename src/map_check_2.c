/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:45:26 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/17 18:05:21 by alejandj         ###   ########.fr       */
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

static int	init_elements(t_path_ctx *ctx)
{
	ctx->queue = malloc(sizeof(t_queue));
	if (!ctx->queue)
		return (0);
	ctx->queue->head = NULL;
	ctx->visited = malloc(sizeof(t_queue));
	if (!ctx->visited)
		return (free(ctx->queue), 0);
	ctx->visited->head = NULL;
	ctx->pos_player = malloc(sizeof(t_pos));
	if (!ctx->pos_player)
	{
		free(ctx->queue);
		free(ctx->visited);
		return (0);
	}
	ctx->pos_player_cpy = malloc(sizeof(t_pos));
	if (!ctx->pos_player_cpy)
	{
		free(ctx->queue);
		free(ctx->visited);
		free(ctx->pos_player);
		return (0);
	}
	return (1);
}

static int	save_initial_pos(char **map, t_path_ctx *ctx)
{
	t_list	*initial_node;
	t_list	*initial_visited;

	get_pos_player(map, ctx->pos_player);
	ctx->pos_player_cpy->x = ctx->pos_player->x;
	ctx->pos_player_cpy->y = ctx->pos_player->y;
	initial_node = ft_lstnew(ctx->pos_player);
	initial_visited = ft_lstnew(ctx->pos_player_cpy);
	if (!initial_node || !initial_visited)
	{
		free(ctx->queue);
		free(ctx->visited);
		free(ctx->pos_player);
		free(ctx->pos_player_cpy);
		return (0);
	}
	ft_lstadd_back(&(ctx->queue->head), initial_node);
	ft_lstadd_back(&(ctx->visited->head), initial_visited);
	return (1);
}

int	check_path(char **map)
{
	t_path_ctx		ctx;

	if (!init_elements(&ctx))
		return (0);
	if (!save_initial_pos(map, &ctx))
		return (0);
	return (travel_map(&ctx, map));
}
