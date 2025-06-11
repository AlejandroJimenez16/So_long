/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:45:26 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/11 20:29:09 by alejandj         ###   ########.fr       */
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

void	get_pos_player(char **map, t_pos *pos)
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
			if (map[i][j] == 'P')
			{
				pos->x = j;
				pos->y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	is_visited(int y, int x, t_queue *visited)
{
	t_list	*current;
	t_pos	*pos;
		
	current = visited->head;
	while (current != NULL)
	{
		pos = (t_pos *)current->content;
		if (pos->x == x && pos->y == y)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_path(char **map)
{
	// Crear e inicializar las listas
	t_queue *queue;
	t_queue	*visited;
	t_pos	*pos_player;
	t_pos	*pos_player_cpy;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->head = NULL;
	
	visited = malloc(sizeof(t_queue));
	if (!visited)
		return (0);
	visited->head = NULL;
	
	pos_player = malloc(sizeof(t_pos));
	if (!pos_player)
		return (0);

	pos_player_cpy = malloc(sizeof(t_pos));
	if (!pos_player_cpy)
		return (0);

	// Obtener posicion del personaje
	get_pos_player(map, pos_player);
	
	// Creo el nodo de la pos inicial y lo guardo en la cola
	t_list	*initial_node;
	t_list	*initial_visited;
	
	pos_player_cpy->x = pos_player->x;
	pos_player_cpy->y = pos_player->y;
	initial_node = ft_lstnew(pos_player);
	initial_visited = ft_lstnew(pos_player_cpy);
	if (!initial_node || !initial_visited)
	{
		free(queue);
		free(pos_player);
		return (0);
	}
	ft_lstadd_back(&(queue->head), initial_node);
	ft_lstadd_back(&(visited->head), initial_visited);
	
	// Empiezo a comprobar desde la posicion inicial
	t_list	*current;
	
	t_list	*node_q;
	t_list	*node_v;
	
	t_pos	*current_pos;
	t_pos	*new_pos;
	t_pos	*new_pos_cpy;
	
	int		x;
	int		y;

	int		total_c;
	int		count_c;

	count_c = 0;
	total_c = get_num_c(map);
	current_pos = malloc(sizeof(t_pos));
	if (!current_pos)
		return (0);
	while (queue->head != NULL)
	{
		current = queue->head;
		current_pos = (t_pos *)current->content;
		x = current_pos->x;
		y = current_pos->y;
		
		// Elimino el nodo
		queue->head = queue->head->next;
		ft_lstdelone(current, free);
		
		// Comprobar posisiones
		if (map[y][x - 1] != '1' && !is_visited(y, x - 1, visited))
		{
			if (map[y][x - 1] == 'E' && count_c == total_c)
				return (1);
			if (map[y][x - 1] == 'C')
				count_c++;
			new_pos = malloc(sizeof(t_pos));
			new_pos_cpy = malloc(sizeof(t_pos));
			if (!new_pos || !new_pos_cpy)
				return (0);
			new_pos->y = y;
			new_pos->x = x - 1;
			new_pos_cpy->x = new_pos->x;
			new_pos_cpy->y = new_pos->y;
			node_q = ft_lstnew(new_pos);
			node_v = ft_lstnew(new_pos_cpy);
			if (!node_q || !node_v)
				return (0);
			ft_lstadd_back(&(queue->head), node_q);
			ft_lstadd_back(&(visited->head), node_v);
		}
		if (map[y - 1][x] != '1' && !is_visited(y - 1, x, visited))
		{
			if (map[y - 1][x] == 'E' && count_c == total_c)
				return (1);
			if (map[y - 1][x] == 'C')
				count_c++;
			new_pos = malloc(sizeof(t_pos));
			new_pos_cpy = malloc(sizeof(t_pos));
			if (!new_pos || !new_pos_cpy)
				return (0);
			new_pos->y = y - 1;
			new_pos->x = x;
			new_pos_cpy->x = new_pos->x;
			new_pos_cpy->y = new_pos->y;
			node_q = ft_lstnew(new_pos);
			node_v = ft_lstnew(new_pos_cpy);
			if (!node_q || !node_v)
				return (0);
			ft_lstadd_back(&(queue->head), node_q);
			ft_lstadd_back(&(visited->head), node_v);
		}
		if (map[y][x + 1] != '1' && !is_visited(y, x + 1, visited))
		{
			if (map[y][x + 1] == 'E' && count_c == total_c)
				return (1);
			if (map[y][x + 1] == 'C')
				count_c++;
			new_pos = malloc(sizeof(t_pos));
			new_pos_cpy = malloc(sizeof(t_pos));
			if (!new_pos || !new_pos_cpy)
				return (0);
			new_pos->y = y;
			new_pos->x = x + 1;
			new_pos_cpy->x = new_pos->x;
			new_pos_cpy->y = new_pos->y;
			node_q = ft_lstnew(new_pos);
			node_v = ft_lstnew(new_pos_cpy);
			if (!node_q || !node_v)
				return (0);
			ft_lstadd_back(&(queue->head), node_q);
			ft_lstadd_back(&(visited->head), node_v);
		}
		if (map[y + 1][x] != '1' && !is_visited(y + 1, x, visited))
		{
			if (map[y + 1][x] == 'E' && count_c == total_c)
				return (1);
			if (map[y + 1][x] == 'C')
				count_c++;
			new_pos = malloc(sizeof(t_pos));
			new_pos_cpy = malloc(sizeof(t_pos));
			if (!new_pos || !new_pos_cpy)
				return (0);
			new_pos->y = y + 1;
			new_pos->x = x;
			new_pos_cpy->x = new_pos->x;
			new_pos_cpy->y = new_pos->y;
			node_q = ft_lstnew(new_pos);
			node_v = ft_lstnew(new_pos_cpy);
			if (!node_q || !node_v)
				return (0);
			ft_lstadd_back(&(queue->head), node_q);
			ft_lstadd_back(&(visited->head), node_v);
		}
	}
	return (0);
}
