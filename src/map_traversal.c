/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_traversal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:08:40 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/14 19:45:57 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	manage_dir(int *y, int *x, int dir)
{
	if (dir == 0)
		(*x)--;
	else if (dir == 1)
		(*y)--;
	else if (dir == 2)
		(*x)++;
	else if (dir == 3)
		(*y)++;
}

int	try_move(char **map, t_path_state *state, t_path_ctx *ctx, int dir)
{
	int	x;
	int	y;
	int	collected;

	x = state->current_pos->x;
	y = state->current_pos->y;
	collected = state->current_pos->collected_c;
	manage_dir(&y, &x, dir);
	if (map[y][x] == 'E')
	{
		if (collected == state->total_c)
			return (1);
		return (0);
	}
	if (map[y][x] == 'C')
		collected++;
	state->new_pos = malloc(sizeof(t_pos));
	state->new_pos_cpy = malloc(sizeof(t_pos));
	if (!state->new_pos || !state->new_pos_cpy)
		return (0);
	state->new_pos->y = y;
	state->new_pos->x = x;
	state->new_pos->collected_c = collected;
	state->new_pos_cpy->y = state->new_pos->y;
	state->new_pos_cpy->x = state->new_pos->x;
	state->new_pos_cpy->collected_c = collected;
	state->node_q = ft_lstnew(state->new_pos);
	state->node_v = ft_lstnew(state->new_pos_cpy);
	if (!state->node_q || !state->node_v)
		return (0);
	ft_lstadd_back(&(ctx->queue->head), state->node_q);
	ft_lstadd_back(&(ctx->visited->head), state->node_v);
	return (0);
}

int	check_neighbors(t_path_state *state, t_path_ctx *ctx, char **map)
{
	int	x;
	int	y;
	int	c;

	x = state->current_pos->x;
	y = state->current_pos->y;
	c = state->current_pos->collected_c;
	if (map[y][x - 1] != '1' && !is_visited(y, x - 1, ctx->visited, c))
		if (try_move(map, state, ctx, 0))
			return (1);
	if (map[y - 1][x] != '1' && !is_visited(y - 1, x, ctx->visited, c))
		if (try_move(map, state, ctx, 1))
			return (1);
	if (map[y][x + 1] != '1' && !is_visited(y, x + 1, ctx->visited, c))
		if (try_move(map, state, ctx, 2))
			return (1);
	if (map[y + 1][x] != '1' && !is_visited(y + 1, x, ctx->visited, c))
		if (try_move(map, state, ctx, 3))
			return (1);
	return (0);
}

int	travel_map(t_path_ctx *ctx, char **map)
{
	t_path_state	state;

	state.total_c = get_num_c(map);
	state.current_pos = malloc(sizeof(t_pos));
	if (!state.current_pos)
		return (0);
	while (ctx->queue->head != NULL)
	{
		state.current = ctx->queue->head;
		state.current_pos = (t_pos *)state.current->content;
		ctx->queue->head = ctx->queue->head->next;
		if (check_neighbors(&state, ctx, map))
		{
			ft_lstdelone(state.current, free);
			return (1);
		}
		ft_lstdelone(state.current, free);
	}
	return (0);
}
