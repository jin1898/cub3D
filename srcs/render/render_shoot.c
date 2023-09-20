/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:56:41 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 03:24:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_shoot(t_game *game)
{
	static int i;

	if (game->hook.state_mouse_left == TRUE)
	{
		draw_line_to_img(&game->scene,
			set_pixel(WIN_W/2, WIN_H/2 + i), 
			set_pixel(WIN_W - 386, WIN_H - 170 + i),
			rgb8_to_int(255, 0, 0));
		draw_line_to_img(&game->scene,
			set_pixel(WIN_W/2, WIN_H/2 + i + 1), 
			set_pixel(WIN_W - 386, WIN_H - 170 + i + 1),
			rgb8_to_int(255, 0, 0));
		i++;
		if (i == 3)
		{
			game->hook.state_mouse_left = FALSE;
			i = 0;
		}
	}
	return;
} 
