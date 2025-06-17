/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:44:26 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/13 18:33:05 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	is_visited(int y, int x, t_queue *visited, int collected_c)
{
	t_list	*current;
	t_pos	*pos;

	current = visited->head;
	while (current != NULL)
	{
		pos = (t_pos *)current->content;
		if (pos->x == x && pos->y == y && pos->collected_c == collected_c)
			return (1);
		current = current->next;
	}
	return (0);
}
