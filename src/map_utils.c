/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:51:51 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/09 01:09:02 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**fill_map(char *file, int count)
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
		return (NULL);
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
