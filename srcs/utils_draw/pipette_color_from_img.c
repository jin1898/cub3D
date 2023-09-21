/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipette_color_from_img.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:08:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/20 17:06:22 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	pipette_color_from_img(t_component *component, t_pixel pixel)
{
	int	res;

	if (pixel.x >= component->width || pixel.y >= component->height
		|| pixel.x < 0 || pixel.y < 0)
		return (0);
	res = component->mlx_data_addr[component->line_size
		/ (component->bpp / 8) * pixel.y + pixel.x];
	if (res == -16777216)
		return (rgb8_to_int(0, 0, 0));
	return (res);
}
