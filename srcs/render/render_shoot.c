/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:56:41 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/25 13:52:10 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_shoot(t_game *game)
{
	if (game->hook.state_mouse_left == TRUE && game->reload_time == 0)
	{
		draw_line_to_img(&game->scene,
			set_pixel(WIN_W / 2, WIN_H / 2 + game->shoot_time),
			set_pixel(WIN_W - 386, WIN_H - 170 + game->shoot_time),
			rgb8_to_int(255, 255, 0));
		draw_line_to_img(&game->scene,
			set_pixel(WIN_W / 2, WIN_H / 2 + game->shoot_time + 2),
			set_pixel(WIN_W - 386, WIN_H - 170 + game->shoot_time + 2),
			rgb8_to_int(255, 255, 0));
		game->shoot_time++;
		if (game->shoot_time == 3)
		{
			game->hook.state_mouse_left = FALSE;
			game->shoot_time = 0;
		}
	}
}
