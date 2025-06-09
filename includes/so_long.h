/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:13 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/09 14:46:48 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

typedef struct s_elements
{
	int	num_e;
	int	num_c;
	int	num_p;
}			t_elements;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_queue
{
	t_list	*head;
}			t_queue;


// Utils
void	free_arr(char **arr);
void	print_errors(char **map, char *msg);

// Map
char	**load_map(char *file);
void	print_map(char **map);
int     count_lines_map(char **map);

// Check Map
int	is_rectangular(char **map);
int check_walls_x(char **map);
int	check_walls_y(char **map);
int	check_min_elements(char **map);
int check_valid_chars(char **map);

#endif