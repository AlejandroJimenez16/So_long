/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:13 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/12 14:14:02 by alejandj         ###   ########.fr       */
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

typedef struct s_path_ctx
{
	t_queue	*queue;
	t_queue	*visited;
	t_pos	*pos_player;
	t_pos	*pos_player_cpy;
}			t_path_ctx;

typedef struct s_path_state
{
	t_list	*current;
	t_list	*node_q;
	t_list	*node_v;
	t_pos	*current_pos;
	t_pos	*new_pos;
	t_pos	*new_pos_cpy;
	int		total_c;
	int		count_c;
}			t_path_state;

// Utils
void	free_arr(char **arr);
void	free_queue(t_queue *queue);
void	print_errors(char **map, char *msg);

// Map_Utils
char	**load_map(char *file);
void	print_map(char **map);
int		count_lines_map(char **map);
int		get_num_c(char **map);
void	get_pos_player(char **map, t_pos *pos);
int		is_visited(int y, int x, t_queue *visited);

// Check Map
int		is_rectangular(char **map);
int		check_walls_x(char **map);
int		check_walls_y(char **map);
int		check_min_elements(char **map);
int		check_valid_chars(char **map);
int		travel_map(t_path_ctx *ctx, char **map);
int		check_path(char **map);

#endif