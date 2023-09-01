/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:18 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/01 19:53:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIN_W 1920
# define WIN_H 1080

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE 1

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_vector
{
	double			x;
	double			y;
}	t_vector;

typedef struct s_check_parse // .cub파씽이 잘들어오는지 확인하는 변수 
{
	size_t	north;
	size_t	south;
	size_t	west;
	size_t	east;
	size_t	floor;
	size_t	ceiling;
	size_t	map;
	size_t	diff; //맵이 여러개인지 확인하는 변수 
}	t_check_parse;

typedef struct s_art
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_art;

typedef struct s_mini
{
	void	*img;
	size_t	size;
	size_t	scale;
	int		*mlx_data_addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_mini;


typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**argv;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	int				floor_color;
	int				ceiling_color;
	char			**map;
	size_t			map_y;
	size_t			map_x;
	int				fd;
	char			*str;
	size_t			line_count;
	t_art			art;
	t_mini			mini;
	t_vector		player_pos;
	t_vector		player_dir;
	t_check_parse	check_parse;
}	t_game;



/* srcs/utils/ */
t_pixel		set_pixel(int x, int y);
int			rgb8_to_int(int r, int g, int b);
int			exit_game(t_game *game);
void		free_split(char	**to_free);
void		free_game(t_game *game);
int			destroy_instance(t_game *game);
int			key_press(int keycode, t_game *game);

/* srcs/utils_shape/ */
void		background_fill(t_game *game, int color);
void		rect(t_game *game, t_pixel first, t_pixel second, int color);
void		line(t_game *game, t_pixel first, t_pixel second, int color);

/* srcs/init/ */
int			init_cub3d(t_game *game, int argc, char **argv);
int			init_cub3d_parse(t_game *game);
int			line_validation(t_game *game);
int			line_validation_texture(t_game *game);
int			line_validation_rgb(t_game *game);
int			line_validation_map(t_game *game);
int			load_images(t_game *game);
int			map_validation(t_game *game);

/* srcs/play/ */
int			reset_mini_map(t_game *game);

/*제출전 지워야하는 함수*/
void		ft_print_dfs_CurrentSituation(char **map);

# endif
