/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:31:35 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/07 20:45:53 by alejandj         ###   ########.fr       */
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
