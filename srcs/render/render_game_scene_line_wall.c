/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_scene_line_wall.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:50:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/16 17:03:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_pipette_wall_by_face(t_game *game, int texture_x, int i, int size)
{
	if (game->ray.last_move == 'y' && game->ray.step.y < 0)
		return (pipette_color_from_img(&game->art.north,
			set_pixel(texture_x, map_int(i, size, game->art.north.height))));
	else if (game->ray.last_move == 'y' && game->ray.step.y > 0)
		return (pipette_color_from_img(&game->art.south,
			set_pixel(texture_x, map_int(i, size, game->art.south.height))));
	else if (game->ray.last_move == 'x' && game->ray.step.x < 0)
		return (pipette_color_from_img(&game->art.west,
			set_pixel(texture_x, map_int(i, size, game->art.west.height))));
	else if (game->ray.last_move == 'x' && game->ray.step.x > 0)
		return (pipette_color_from_img(&game->art.east,
			set_pixel(texture_x, map_int(i, size, game->art.east.height))));
}

void	render_game_scene_line_wall(t_game *game,
	t_ray *ray, int size, int start_y)
{
	int	i;
	int	texture_x;

	i = 0;
	texture_x = (int)map_double(ray->hit_point, 1, 1000);
	while (i < size)
	{
		draw_pixel_to_img(
			&game->scene,
			set_pixel(ray->camera_x, start_y + i),
			_pipette_wall_by_face(game, texture_x, i, size));
		i++;
	}
}