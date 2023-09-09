/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:18 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/09 21:09:51 by jsunwoo          ###   ########.fr       */
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
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_MOTION_NOTIFY 6
# define X_EVENT_DESTROY 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define UNIT_DEGREE 3

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE 1

# define UNIT_DEGREE 3
# define DISTANCE_UNIT 0.05

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
	size_t	diff;
}	t_check_parse;

typedef struct s_art
{//t_component로 바꿔야 이미지정보를 넣을수있다.
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_art;

typedef struct s_component
{
	void	*img;
	int		width;
	int		height;
	int		*mlx_data_addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_component;

typedef struct s_hook
{
	int		state_key_w;
	int		state_key_a;
	int		state_key_s;
	int		state_key_d;
	int		state_key_left;
	int		state_key_right;
	int		prev_mouse_x;
}	t_hook;

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
	double			mini_map_tile_size;
	int				fd;
	char			*str;
	size_t			line_count;
	t_art			art;
	t_hook			hook;
	t_component		mini;
	t_component		scene;
	t_vector		player;
	t_vector		view_angle;
	t_vector		plane_angle;
	t_check_parse	check_parse;
}	t_game;

/* srcs/utils/ */



int			exit_game(t_game *game);
void		free_split(char	**to_free);
void		free_game(t_game *game);
int			destroy_instance(t_game *game);


/* srcs/init/ */
int			init_cub3d(t_game *game, int argc, char **argv);
int			init_cub3d_parse(t_game *game);
int			line_validation(t_game *game);
int			line_validation_texture(t_game *game);
int			line_validation_rgb(t_game *game);
int			line_validation_map(t_game *game);
int			load_images(t_game *game);
int			map_validation(t_game *game);
int			map_validation_is_surround(char **map, t_game *game);
int			map_validation_dfs(size_t x, size_t y,
				int *ismap_empty, char **test_map);

/* srcs/render/ */
void		render_mini_map(t_game *game);
void		render_game_scene(t_game *game);

/* srcs/loop/ */
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			mouse_move(int x, int y, t_game *game);
int			loop_hook(t_game *game);
void		reset_vector(t_game *game, t_hook hook, char **map);

/* srcs/utils_draw/ */
void		draw_pixel_to_img(t_component *component,
				t_pixel pixel, int color);
void		draw_line_to_img(t_component *component,
				t_pixel first, t_pixel second, int color);
void		draw_rect_to_img(t_component *component,
				t_pixel first, t_pixel second, int color);
int			rgb8_to_int(int r, int g, int b);
t_pixel		set_pixel(int x, int y);

/* srcs/utils_math/ */
double		deg_to_rad(double degree);
t_vector	add_vector(t_vector vector1, t_vector vector2);
t_vector	substract_vector(t_vector vector1, t_vector vector2);
t_vector	rotate_vector(t_vector vector, double degree);
t_vector	set_vector(double x, double y);
t_vector	move_vector(t_vector pos, t_vector dir, double distance);

/* map_validation_dfs.c */

//함수파일명_함수기능으로 이름적기
//파일1개에는 1개의 함수만 호출되도록 만들기
//srcs/init에 넣기
//릭

/*제출전 지워야하는 함수*/
void		ft_print_dfs_CurrentSituation(char **map);

#endif
