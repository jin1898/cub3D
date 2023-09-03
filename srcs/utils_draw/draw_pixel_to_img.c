/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_to_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:54:44 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/03 17:33:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel_to_img(t_component *component, t_pixel pixel, int color)
{ //component의 이미지에서 pixel 위치에 color 를 점찍음 
	if (pixel.x >= component->width || pixel.y >= component->height
		|| pixel.x < 0 || pixel.y < 0) // 세그폴트 방지
		return ;
	component->mlx_data_addr[component->line_size /
		(component->bpp / 8) * pixel.y + pixel.x] = color; // 색칠하기
}
