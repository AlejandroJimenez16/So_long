/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:51:51 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/18 20:22:47 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**fill_map(char *file, int count)
{
	int		i;
	char	*line;
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc((count + 1) * sizeof(char *));
	if (!map)
	{
		close (fd);
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**load_map(char *file)
{
	int		fd;
	int		count;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count == 0)
		return (NULL);
	map = fill_map(file, count);
	return (map);
}

void	print_map(char **map)
{
	int	j;
	int	num_map_lines;

	num_map_lines = count_lines_map(map) - 1;
	j = 0;
	while (map[j] != NULL)
	{
		if (j == num_map_lines)
		{
			ft_printf("%s\n", map[j]);
			break ;
		}
		ft_printf("%s", map[j]);
		j++;
	}
}

int	count_lines_map(char **map)
{
	int	j;

	j = 0;
	while (map[j] != NULL)
		j++;
	return (j);
}

int	get_num_c(char **map)
{
	int	i;
	int	j;
	int	map_lines;
	int	total_c;

	map_lines = count_lines_map(map) - 1;
	total_c = 0;
	i = 0;
	while (i < map_lines)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				total_c++;
			j++;
		}
		i++;
	}
	return (total_c);
}
