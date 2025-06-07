/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:45:26 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/07 21:52:38 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_elements(char **map, int i, t_elements *elements)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] == 'E')
			elements->num_e++;
		else if (map[i][j] == 'C')
			elements->num_c++;
		else if (map[i][j] == 'P')
			elements->num_p++;
		j++;
	}
}

int	check_min_elements(char **map)
{
	int			i;
	int			map_lines;
	t_elements	elements;

	elements.num_e = 0;
	elements.num_c = 0;
	elements.num_p = 0;
	map_lines = count_lines_map(map) - 1;
	i = 0;
	while (i < map_lines)
	{
		count_elements(map, i, &elements);
		i++;
	}
	if (elements.num_e != 1 || elements.num_c < 1 || elements.num_p != 1)
		return (0);
	return (1);
}

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
