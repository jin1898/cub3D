/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:06:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/03 17:51:47 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_rect_to_img(t_component *component,
	t_pixel first, t_pixel second, int color)
{ //직사각형그리는함수 first.x에서 second.x를 뺀다음 모두 점으로 채워넣음
	int	x;
	int y;

	x = first.x;
	while (x < second.x)
	{
		y = first.y;
		while (y < second.y)//y만큼 다 점으로 찍어버림 (draw_pixel_to_img함수 기능임)
		{
			draw_pixel_to_img(component, set_pixel(x, y), color);
			y++;
		}
		x++;
	}
}
