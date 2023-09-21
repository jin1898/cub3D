/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:06:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/15 23:50:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_rect_to_img(t_component *component,
	t_pixel first, t_pixel second, int color)
{
	int	x;
	int	y;

	x = first.x;
	while (x < second.x)
	{
		y = first.y;
		while (y < second.y)
		{
			draw_pixel_to_img(component, set_pixel(x, y), color);
			y++;
		}
		x++;
	}
}
