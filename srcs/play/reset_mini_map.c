/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_mini_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:19:25 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/01 20:22:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_draw_rect(t_game *game, t_pixel first, int color)
{
	int	x;
	int	y;

	x = first.x;
	while (x < first.x + (int)game->mini.scale)
	{
		y = first.y;
		while (y < first.y + (int)game->mini.scale)
		{
			game->mini.mlx_data_addr[game->mini.line_size /
				(game->mini.bpp / 8) * y + x] = color; 
			y++;
		}
		x++;
	}
	return ;
}


int	reset_mini_map(t_game *game)
{
	game->mini.size = WIN_W / 6.4;
	game->mini.img = mlx_new_image(game->mlx, game->mini.size, game->mini.size);
	game->mini.mlx_data_addr = (int *)mlx_get_data_addr(game->mini.img,
		&game->mini.bpp, &game->mini.line_size, &game->mini.endian);
	if(game->map_x > game->map_y)
		game->mini.scale = game->mini.size / (game->map_x - 2);
	else
		game->mini.scale = game->mini.size / (game->map_y - 2);

	for (size_t y = 0; y < game->mini.size; y++) // 미니맵 배경칠하기
		for (size_t x = 0; x < game->mini.size; x++)
			game->mini.mlx_data_addr[game->mini.line_size
				/ (game->mini.bpp / 8) * y + x] = rgb8_to_int(77, 45, 183);

	for (size_t y = 0; game->map[y]; y++) // 벽만 칠하기
		for (size_t x = 0; game->map[y][x]; x++)
			if (game->map[y][x] == '1')
				_draw_rect(game,
					set_pixel(x * game->mini.scale, y * game->mini.scale),
						rgb8_to_int(157, 68, 192));

	// 만든 이미지 띄우기
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
		WIN_W - game->mini.size - 20, WIN_H - game->mini.size - 20);
	return (0);
}

// rgb(157, 68, 192) 벽벽

// rgb(236, 83, 176) 주인공