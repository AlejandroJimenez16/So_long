/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:13:42 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/05 13:20:18 by alejandj         ###   ########.fr       */
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
		char	**map;
		
		// Comprobacion extension correcta
		if (!check_file_extension(argv[1]))
		{
			ft_putstr_fd("\033[1;31mINCORRECT FILE EXTENSION\n\033[0m", 2);
			return (1);
		}
		
		// Llenar el mapa
		map = load_map(argv[1]);

		//Comprobacion mapa rectangular
		if (!is_rectangular(map))
		{
			ft_putstr_fd("\033[1;31mNO ES RECTANGULAR\n\033[0m", 2);
			return (1);
		}
		ft_printf("ES RECTANGULAR\n");
		
		// Comprobacion mapa cerrado
		if (!check_walls_X(map) || !check_walls_Y(map))
		{
			ft_putstr_fd("\033[1;31mNO TA BN CERRADO EL MAPA\n\033[0m", 2);
			return (1);
		}
		ft_printf("TA BN CERRADO\n");
		
		//mostrar lineas map
		//print_map(map);
		
		free_arr(map);
	}
	else
		ft_putstr_fd("\033[1;31mINCORRECT ARGS\n\033[0m", 2);
}