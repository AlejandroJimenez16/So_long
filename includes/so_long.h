/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:13 by alejandj          #+#    #+#             */
/*   Updated: 2025/06/18 14:37:56 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

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

typedef struct s_window
{
	void	*win;
	int		win_width;
	int		win_height;
	int		rows;
	int		cols;
}			t_window;

typedef struct s_sprites
{
	void		*wall;
	void		*floor;
	void		*player_up;
	void		*player_down;
	void		*player_left;
	void		*player_right;
	void		*player_current;
	void		*collectionable;
	void		*exit;
	void		*exit_final;
}				t_sprites;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	char		**map;
	t_sprites	sprites;
	t_pos		pos_player;
	int			count_c;
	int			count_moves;
}				t_game;

// Utils
void	free_arr(char **arr);
void	print_errors(char **map, char *msg);
int		close_game(t_game *game);

// Map_Utils
char	**load_map(char *file);
void	print_map(char **map);
int		count_lines_map(char **map);
int		get_num_c(char **map);
void	get_pos_player(char **map, t_pos *pos);
char	**duplicate_map(char **map);

// Check Map
int		is_rectangular(char **map);
int		check_walls_x(char **map);
int		check_walls_y(char **map);
int		check_min_elements(char **map);
int		check_valid_chars(char **map);
int		check_path(char **map);

// MLX
int		init_mlx(t_game	*game);
int		create_window(t_game *game);

// Events
int		handle_key(int keycode, t_game *game);

// Render
void	load_sprites(t_game *game);
void	render_map(t_game *game);

#endif