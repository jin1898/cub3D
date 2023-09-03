/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:19:25 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/01 20:22:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_mini_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_rect_to_img(&game->mini,
		set_pixel(0, 0), set_pixel(game->mini.width, game->mini.height),
		rgb8_to_int(77, 45, 183));
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_rect_to_img(&game->mini,
					set_pixel(x * game->mini_map_tile_scale,
						y * game->mini_map_tile_scale),
					set_pixel(x * game->mini_map_tile_scale
						+ game->mini_map_tile_scale,
						y * game->mini_map_tile_scale
						+ game->mini_map_tile_scale),
					rgb8_to_int(157, 68, 192));
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
		WIN_W - game->mini.width - 20, WIN_H - game->mini.height - 20);
	return (0);
}

// rgb(77, 45, 183) 배경색
// rgb(157, 68, 192) 벽벽
// rgb(236, 83, 176) 주인공