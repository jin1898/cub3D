/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:18 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/26 20:50:15 by sunwoo-jin       ###   ########.fr       */
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

# define WIN_W 1280
# define WIN_H 720

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_MOTION_NOTIFY 6
# define X_EVENT_DESTROY 17
# define X_EVENT_MOUSE_PRESS 4
# define X_EVENT_MOUSE_RELEASE 5

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE 1

# define DEGREE_UNIT 3
# define DISTANCE_UNIT 0.05
# define MOUSE_SPEED 0.08

typedef struct s_listNode
{
	struct listNode	*next;
	int				y;
	int				x;
}	t_node;

typedef struct s_pixel
{
	int				x;
	int				y;
}	t_pixel;

typedef struct s_vector
{
	double			x;
	double			y;
}	t_vector;

typedef struct s_check_parse
{
	size_t			north;
	size_t			south;
	size_t			west;
	size_t			east;
	size_t			floor;
	size_t			ceiling;
	size_t			map;
	size_t			diff;
}	t_check_parse;

typedef struct s_component
{
	void			*img;
	int				width;
	int				height;
	int				*mlx_data_addr;
	int				bpp;
	int				line_size;
	int				endian;
}	t_component;

typedef struct s_art
{
	t_component		north;
	t_component		south;
	t_component		west;
	t_component		east;
	t_component		ammo;
	t_component		title_menu;
	t_component		mouse_cursor;
	t_component		hand_idle;
	t_component		hand_shoot;
	t_component		hand_reload_1;
	t_component		hand_reload_2;
}	t_art;

typedef struct s_hook
{
	int				state_key_w;
	int				state_key_a;
	int				state_key_s;
	int				state_key_d;
	int				state_key_r;
	int				state_key_left;
	int				state_key_right;
	int				state_mouse_left;
	int				state_mouse_right;
	int				prev_mouse_x;
	int				loop_hook_term;
}	t_hook;

typedef struct s_ray
{
	t_vector		dir;
	t_vector		step;
	t_vector		delta;
	t_vector		belong;
	t_vector		side;
	double			hit_point;
	char			last_move;
	char			face;
	int				camera_x;
}	t_ray;

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
	t_vector		mini_map_margin;
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
	t_ray			ray;
	int				ammo_count;
	int				reload_time;
	int				shoot_time;
	t_pixel			mouse_cursor;
}	t_game;

/* srcs/hook/ */
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			mouse_move(int x, int y, t_game *game);
int			mouse_press(int keycode, int x, int y, t_game *game);
int			mouse_release(int keycode, int x, int y, t_game *game);
int			loop_hook(t_game *game);
void		reset_vector(t_game *game, t_hook hook, char **map);
int			title_menu_loop_hook(t_game *game);
int			title_menu_mouse_move(int x, int y, t_game *game);
int			title_menu_mouse_press(int keycode, int x, int y, t_game *game);
int			title_menu_key_press(int keycode, t_game *game);

/* srcs/init/ */
int			init_cub3d(t_game *game, int argc, char **argv);
int			init_cub3d_parse(t_game *game);
int			line_validation(t_game *game);
int			line_validation_texture(t_game *game);
int			line_validation_rgb(t_game *game);
int			line_validation_get_rgb8(t_game *game, char **rgb);
int			line_validation_map(t_game *game);
int			load_images(t_game *game);
void		load_images_texture(t_game *game, t_art *art);
int			map_validation(t_game *game);
int			map_validation_is_surround(char **map, t_game *game);
int			map_validation_dfs(size_t x, size_t y,
				int *is_map_empty, char **test_map);
void		reset_terminal_interface(t_game *game);

/* srcs/render/ */
void		render_mini_map(t_game *game);
void		render_game_scene(t_game *game);
void		render_game_scene_line(t_game *game, double distance);
void		render_game_scene_line_wall(t_game *game,
				t_ray *ray, double distance, int start_y);
void		render_cross_hair(t_game *game);
void		render_shoot(t_game *game);
void		render_hand(t_game *game);
void		render_ammo_count(t_game *game);

/* srcs/utils/ */
int			exit_game(t_game *game);
void		free_split(char	**to_free);
void		free_game(t_game *game);
int			destroy_instance(t_game *game);

/* srcs/utils_draw/ */
void		draw_pixel_to_img(t_component *component,
				t_pixel pixel, int color);
void		draw_line_to_img(t_component *component,
				t_pixel first, t_pixel second, int color);
void		draw_rect_to_img(t_component *component,
				t_pixel first, t_pixel second, int color);
int			pipette_color_from_img(t_component *component,
				t_pixel pixel);
int			rgb8_to_int(int r, int g, int b);
t_pixel		set_pixel(int x, int y);

/* srcs/utils_math/ */
double		deg_to_rad(double degree);
t_vector	add_vector(t_vector vector1, t_vector vector2);
t_vector	substract_vector(t_vector vector1, t_vector vector2);
t_vector	rotate_vector(t_vector vector, double degree);
t_vector	set_vector(double x, double y);
t_vector	move_vector(t_vector pos, t_vector dir, double distance);
double		distance_vector(t_vector v1, t_vector v2);
double		map_double(double num, double in_max, double out_max);
int			map_int(int num, int in_max, int out_max);

/* srcs/utils_ray_casting/ */
double		ray_casting(t_game *game, t_ray *ray, t_vector pos, t_vector dir);
void		init_ray_casting(t_ray *ray, t_vector pos, t_vector dir);

#endif
