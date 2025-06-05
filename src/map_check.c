/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:31:35 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/05 13:18:48 by alejandj         ###   ########.fr       */
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

int	check_walls_X(char **map)
{
	int	i;
	int	len;
	int	num_lines_Y;

	len = ft_strlen(map[0]) - 1;
	num_lines_Y = count_lines_map(map) - 1;	
	i = 0;
	while (i < len)
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (map[num_lines_Y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls_Y(char **map)
{
	int	i;
	int	len;
	int	num_lines_Y;

	num_lines_Y = count_lines_map(map) - 1;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	len = ft_strlen(map[num_lines_Y]) - 1;
	i = 0;
	while (map[i])
	{
		if (i == num_lines_Y)
		{
			len = ft_strlen(map[0]) - 2;
			if (map[i][len] != '1')
				return (0);
		}
		else if (map[i][len] != '1')
			return (0);
		i++;
	}	
	return (1);
}