/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:44:26 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/18 14:38:22 by alejandj         ###   ########.fr       */
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

char	**duplicate_map(char **map)
{
	int		i;
	int		j;
	int		map_lines;
	char	**copy;

	i = 0;
	map_lines = count_lines_map(map);
	copy = malloc((map_lines + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < map_lines)
	{
		copy[i] = malloc((ft_strlen(map[i]) + 1) * sizeof(char));
		if (!copy[i])
			return (NULL);
		j = -1;
		while (map[i][++j] != '\0')
			copy[i][j] = map[i][j];
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
