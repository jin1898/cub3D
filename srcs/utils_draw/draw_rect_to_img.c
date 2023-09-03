/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:06:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/03 14:52:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_rect_to_img(t_component *component,
	t_pixel first, t_pixel second, int color)
{
	int	i;
	int j;

	i = first.x;
	while (i < second.x)
	{
		j = first.y;
		while (j < second.y)
		{
			draw_pixel_to_img(component, set_pixel(i, j), color);
			j++;
		}
		i++;
	}
}