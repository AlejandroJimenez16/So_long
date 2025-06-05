/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:13 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/05 13:01:14 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

// Utils
void	free_arr(char **arr);
void	print_errors(char **map);

// Map
char	**load_map(char *file);
void	print_map(char **map);
int     count_lines_map(char **map);

// Check Map
int	is_rectangular(char **map);
int check_walls_X(char **map);
int	check_walls_Y(char **map);

#endif