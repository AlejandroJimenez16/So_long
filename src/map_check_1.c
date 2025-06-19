/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:31:35 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/19 11:55:05 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(char **map)
{
	int		i;
	size_t	len;
	int		num_lines;

	i = 1;
	num_lines = count_lines_map(map) - 1;
	len = ft_strlen(map[0]) - 1;
	if ((int)len == num_lines + 1)
		return (0);
	while (map[i])
	{
		if (i == num_lines)
		{
			if ((ft_strlen(map[i])) != len)
				return (0);
		}
		else if ((ft_strlen(map[i]) - 1) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls_x(char **map)
{
	int	i;
	int	len;
	int	num_lines_y;

	len = ft_strlen(map[0]) - 1;
	num_lines_y = count_lines_map(map) - 1;
	i = 0;
	while (i < len)
	{
		if (map[0][i] != '1' || map[num_lines_y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls_y(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]) - 2;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	count_elements(char **map, int i, t_elements *elements)
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
