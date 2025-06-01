/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:13:42 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/01 21:12:28 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file_extension(char *str)
{
	char **file_name;
	int		len;

	file_name = ft_split(str, '.');
	len = ft_strlen(file_name[1]);
	if (len != 3 || (ft_strncmp("ber", file_name[1], 3) != 0))
	{
		free_arr(file_name);
		return (0);
	}
	free_arr(file_name);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int		fd;
		char	*line;
		int		count;
		char	**map;
		int		i;
		
		// Comprobacion extension correcta
		if (!check_file_extension(argv[1]))
		{
			ft_putstr_fd("\033[1;31mINCORRECT FILE EXTENSION\n\033[0m", 2);
			return (1);
		}
		
		// Crear array con el mapa
		fd = open(argv[1], O_RDONLY);
		count = 0;
		if (fd < 0)
			return (1);
		
		//Contar cuantas lineas hay
		line = get_next_line(fd);
		while (line != NULL)
    	{
			count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		fd = open(argv[1], O_RDONLY);
		
		//Reservar memoria para el mapa
		map = malloc((count + 1) * sizeof(char *));
		if (!map)
			return (1);

		//Leer y meter cada linea en el map
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

		//mostrar lineas map
		int j = 0;
		while (map[j] != NULL)
		{
			ft_printf("%s", map[j]);
			j++;
		}
	}
	else
		ft_putstr_fd("\033[1;31mINCORRECT ARGS\n\033[0m", 2);
}