/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:57:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 15:00:05 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_render_background(t_component *comp)
{
	draw_rect_to_img(
		comp,
		set_pixel(0, 0),
		set_pixel(comp->width, comp->height),
		rgb8_to_int(39, 40, 41));
	draw_rect_to_img(
		comp,
		set_pixel(3, 3),
		set_pixel(comp->width - 3, comp->height -3),
		rgb8_to_int(97, 103, 122));
}

static void	_render_wall(t_component *comp,
	double x, double y, double tile_size)
{
	draw_rect_to_img(
		comp,
		set_pixel(
			round(x * tile_size),
			round(y * tile_size)),
		set_pixel(
			round((x * tile_size) + tile_size),
			round((y * tile_size) + tile_size)),
		rgb8_to_int(39, 40, 41));
	draw_rect_to_img(
		comp,
		set_pixel(
			round(x * tile_size) + 3,
			round(y * tile_size) + 3),
		set_pixel(
			round((x * tile_size) + tile_size) - 3,
			round((y * tile_size) + tile_size) - 3),
		rgb8_to_int(97, 103, 122));
}

static void	_render_player(t_game *game, double x, double y, double tile_size)
{
	t_vector	view_pos;

	view_pos = add_vector(set_vector(x, y), game->view_angle);
	draw_line_to_img(
		&game->mini,
		set_pixel(
			(x * tile_size),
			(y * tile_size)),
		set_pixel(
			view_pos.x * tile_size,
			view_pos.y * tile_size),
		rgb8_to_int(255, 255, 255));
	draw_rect_to_img(
		&game->mini,
		set_pixel(
			(x * tile_size) - 2,
			(y * tile_size) - 2),
		set_pixel(
			(x * tile_size) + 2,
			(y * tile_size) + 2),
		rgb8_to_int(216, 217, 218));
}

static void	_get_mini_map_margin(t_game *game)
{
	if (game->map_y > game->map_x)
	{
		game->mini_map_margin.x = 0;
		game->mini_map_margin.y = (double)(game->map_y - game->map_x) / 2.0;
	}
	else if (game->map_y < game->map_x)
	{
		game->mini_map_margin.x = (double)(game->map_x - game->map_y) / 2.0;
		game->mini_map_margin.y = 0;
	}
	else
	{
		game->mini_map_margin.x = 0;
		game->mini_map_margin.y = 0;
	}
}

void	render_mini_map(t_game *game)
{
	t_pixel	pos;

	pos = set_pixel(0, 0);
	_get_mini_map_margin(game);
	_render_background(&game->mini);
	while (game->map[pos.y])
	{
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == '1')
				_render_wall(&game->mini,
					pos.x + game->mini_map_margin.x,
					pos.y + game->mini_map_margin.y,
					game->mini_map_tile_size);
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
	}
	_render_player(game,
		game->player.x + game->mini_map_margin.x,
		game->player.y + game->mini_map_margin.y,
		game->mini_map_tile_size);
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
		WIN_W - game->mini.width - 20, WIN_H - game->mini.height - 20);
}
