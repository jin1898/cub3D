/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cross_hair.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:56:41 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/16 17:05:46 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_cross_hair(t_game *game)
{
	int	length;
	int	stroke;
	
	length = 15;
	stroke = 1;
	draw_rect_to_img(&game->scene,
		set_pixel(WIN_W / 2 - stroke, WIN_H / 2 - length),
		set_pixel(WIN_W / 2 + stroke, WIN_H / 2 + length),
		rgb8_to_int(0, 255, 0));
	draw_rect_to_img(&game->scene,
		set_pixel(WIN_W / 2 - length, WIN_H / 2 - stroke),
		set_pixel(WIN_W / 2 + length, WIN_H / 2 + stroke),
		rgb8_to_int(0, 255, 0));
}
