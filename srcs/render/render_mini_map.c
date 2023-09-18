/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:57:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/18 22:59:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_render_background(t_component *comp)
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
//배경색 칠하는 함수

void	_render_wall(t_component *comp, int x, int y, double tile_size)
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
// 벽 (1칸) 그리는 함수

void	_render_player(t_game *game, double x, double y, double tile_size)
{
	t_vector	view_pos;

	view_pos = add_vector(game->player, game->view_angle);
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
// 플레이어 그리는 함수

void	render_mini_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	_render_background(&game->mini);
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				_render_wall(&game->mini, x, y, game->mini_map_tile_size);
			x++;
		}
		y++;
		x = 0;
	}
	_render_player(game, game->player.x, game->player.y,
		game->mini_map_tile_size);
}
