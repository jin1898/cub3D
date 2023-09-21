/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cross_hair.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:56:41 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/18 23:09:26 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_draw_cross_hair(t_game *game,
	int length, int stroke, int aim_spread)
{
	int	color;

	color = rgb8_to_int(0, 255, 0);
	draw_rect_to_img(&game->scene,
		set_pixel(WIN_W / 2 - stroke, WIN_H / 2 - length - aim_spread),
		set_pixel(WIN_W / 2 + stroke, WIN_H / 2 - aim_spread),
		color);
	draw_rect_to_img(&game->scene,
		set_pixel(WIN_W / 2 - stroke, WIN_H / 2 + aim_spread),
		set_pixel(WIN_W / 2 + stroke, WIN_H / 2 + length + aim_spread),
		color);
	draw_rect_to_img(&game->scene,
		set_pixel(WIN_W / 2 - length - aim_spread, WIN_H / 2 - stroke),
		set_pixel(WIN_W / 2 - aim_spread, WIN_H / 2 + stroke),
		color);
	draw_rect_to_img(&game->scene,
		set_pixel(WIN_W / 2 + aim_spread, WIN_H / 2 - stroke),
		set_pixel(WIN_W / 2 + length + aim_spread, WIN_H / 2 + stroke),
		color);
	stroke++;
	draw_rect_to_img(&game->scene,
		set_pixel(WIN_W / 2 - stroke, WIN_H / 2 - stroke),
		set_pixel(WIN_W / 2 + stroke, WIN_H / 2 + stroke),
		color);
}

static int	_count_move_key_press(t_hook hook)
{
	int	res;

	res = 0;
	res += hook.state_key_a;
	res += hook.state_key_d;
	res += hook.state_key_s;
	res += hook.state_key_w;
	return (res);
}

void	render_cross_hair(t_game *game)
{
	int	length;
	int	stroke;

	length = 15;
	stroke = 1;
	if (_count_move_key_press(game->hook) == 0)
		_draw_cross_hair(game, length, stroke, 10);
	else
		_draw_cross_hair(game, length, stroke, 25);
}
