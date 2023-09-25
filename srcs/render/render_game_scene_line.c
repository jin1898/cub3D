/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_scene_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:35:26 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/22 23:55:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_render_line_ceiling(t_game *game, int start_y)
{
	int	i;

	i = 0;
	while (i < start_y)
	{
		draw_pixel_to_img(&game->scene,
			set_pixel(game->ray.camera_x, i),
			game->ceiling_color);
		i++;
	}
}

static void	_render_line_floor(t_game *game, int end_y)
{
	int	i;

	i = end_y;
	while (i < WIN_H)
	{
		draw_pixel_to_img(&game->scene,
			set_pixel(game->ray.camera_x, i),
			game->floor_color);
		i++;
	}
}

void	render_game_scene_line(t_game *game, double distance)
{
	int	size;
	int	start_y;
	int	end_y;

	size = 1 / distance * (WIN_H);
	start_y = (WIN_H / 2) - (size / 2);
	render_game_scene_line_wall(game, &game->ray, distance, start_y);
	if (distance <= 1)
		return ;
	end_y = start_y + size;
	_render_line_ceiling(game, start_y);
	_render_line_floor(game, end_y);
}
