/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ammo_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:34:51 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/26 14:57:15 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_put_resized_img(t_pixel pos, t_pixel size,
	t_component *scene, t_component *img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	x = 0;
	while (y < size.y)
	{
		while (x < size.y)
		{
			color = pipette_color_from_img(img,
					set_pixel(map_int(x, size.x, img->width),
						map_int(y, size.y, img->height)));
			if (color > 0)
				draw_pixel_to_img(scene, set_pixel(pos.x + x, pos.y + y),
					color);
			x++;
		}
		y++;
		x = 0;
	}
}

static void	_render_ammo(t_game *game, int index)
{
	_put_resized_img(set_pixel(10 + index * 40, WIN_H - 65),
		set_pixel(40, 60), &game->scene, &game->art.ammo);
}

void	render_ammo_count(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->ammo_count)
	{
		_render_ammo(game, i);
		i++;
	}
}
