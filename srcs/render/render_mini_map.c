/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:57:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/06 15:26:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_render_background(t_component *comp)
{
	draw_rect_to_img(
		comp,
		set_pixel(0, 0),
		set_pixel(comp->width, comp->height),
		rgb8_to_int(236, 83, 176));
	draw_rect_to_img(
		comp,
		set_pixel(3, 3),
		set_pixel(comp->width - 3, comp->height -3),
		rgb8_to_int(157, 68, 192));
}
//배경색 칠하는 함수

void	_render_wall(t_component *comp, int x, int y, double tile_size)
{
	draw_rect_to_img(
		comp,
		set_pixel(
			(x * tile_size),
			(y * tile_size)),
		set_pixel(
			(x * tile_size) + tile_size,
			(y * tile_size) + tile_size),
		rgb8_to_int(77, 45, 183));
}
// 벽 (1칸) 그리는 함수

void	_render_player(t_game *game, double x, double y, double tile_size)
{
	t_vector	view_pos;

	view_pos = add_vector(game->player, game->view_angle);
	draw_line_to_img(
		&game->mini,
		set_pixel(
			(x * tile_size) + tile_size / 2,
			(y * tile_size) + tile_size / 2),
		set_pixel(
			view_pos.x * tile_size + tile_size / 2,
			view_pos.y * tile_size + tile_size / 2),
		rgb8_to_int(255, 255, 255));
	draw_rect_to_img(
		&game->mini,
		set_pixel(
			(x * tile_size) - 2 + tile_size / 2,
			(y * tile_size) - 2 + tile_size / 2),
		set_pixel(
			(x * tile_size) + 2 + tile_size / 2,
			(y * tile_size) + 2 + tile_size / 2),
		rgb8_to_int(255, 255, 255));
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
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
		WIN_W - game->mini.width - 20, WIN_H - game->mini.height - 20);
}
//미니맵을 mlx 이미지 인스턴스에 그리는 함수
// rgb(77, 45, 183) 배경색
// rgb(157, 68, 192) 벽벽
// rgb(236, 83, 176) 주인공
//사운드 엔지니어링 사운드 개발자 Ableton Live 11 Suite