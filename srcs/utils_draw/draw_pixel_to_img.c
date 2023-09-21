/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_to_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:54:44 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/15 23:48:55 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel_to_img(t_component *component, t_pixel pixel, int color)
{
	if (pixel.x >= component->width || pixel.y >= component->height
		|| pixel.x < 0 || pixel.y < 0)
		return ;
	component->mlx_data_addr[component->line_size
		/ (component->bpp / 8) * pixel.y + pixel.x] = color;
}
