/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:57:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/05 20:38:51 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_render_player(t_game *game)
{
	t_vector	view_pos;

	view_pos = add_vector(game->player, game->view_angle);
	draw_line_to_img(
		&game->mini,
		set_pixel(
			game->player.x * game->mini_map_tile_size,
			game->player.y * game->mini_map_tile_size + (((game->map_y - game->map_x) * game->mini_map_tile_size) / 2)
		),
		set_pixel(
			view_pos.x * game->mini_map_tile_size,
			view_pos.y * game->mini_map_tile_size + (((game->map_y - game->map_x) * game->mini_map_tile_size) / 2)
		),
		rgb8_to_int(255, 255, 255)
	);
	draw_rect_to_img(
		&game->mini,
		set_pixel(
			game->player.x * game->mini_map_tile_size - 2,
			game->player.y * game->mini_map_tile_size - 2 + (((game->map_y - game->map_x) * game->mini_map_tile_size) / 2)
		),
		set_pixel(
			game->player.x * game->mini_map_tile_size + 2,
			game->player.y * game->mini_map_tile_size + 2 + (((game->map_y - game->map_x) * game->mini_map_tile_size) / 2)
		),
		rgb8_to_int(255, 255, 255)
	);
}

void	render_mini_map(t_game *game)
{//미니맵의 벽을 그려서 완성시킴
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_rect_to_img(&game->mini,
		set_pixel(0, 0), set_pixel(game->mini.width, game->mini.height),
		rgb8_to_int(236, 83, 176)); //미니맵의 창이 아니라 이미지를 그림. 창안에 나중에 넣을꺼임
	draw_rect_to_img(&game->mini,
		set_pixel(3, 3), set_pixel(game->mini.width - 3, game->mini.height - 3),
		rgb8_to_int(157, 68, 192)); //미니맵의 창이 아니라 이미지를 그림. 창안에 나중에 넣을꺼임
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_rect_to_img(&game->mini,
					set_pixel(x * game->mini_map_tile_size,
						y * game->mini_map_tile_size + (((game->map_y - game->map_x) * game->mini_map_tile_size) / 2)), // 중앙정렬용
					set_pixel(x * game->mini_map_tile_size
						+ game->mini_map_tile_size,
						y * game->mini_map_tile_size
						+ game->mini_map_tile_size + (((game->map_y - game->map_x) * game->mini_map_tile_size) / 2)), // 중앙정렬용
					rgb8_to_int(77, 45, 183)); //while문 돌면서 1개 벽만큼의 크기를 색으로 채워줌.
			x++;
		}
		y++;
		x = 0;
	}
	_render_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
		WIN_W - game->mini.width - 20, WIN_H - game->mini.height - 20);
		 //윈도우창(3D이미자와 미니맵이 올라갈예정이던창)에 올라감
}

// rgb(77, 45, 183) 배경색
// rgb(157, 68, 192) 벽벽
// rgb(236, 83, 176) 주인공

//사운드 엔지니어링 사운드 개발자 Ableton Live 11 Suite