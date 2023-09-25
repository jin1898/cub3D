/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_scene_line_wall.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:50:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/25 13:51:44 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_pipette_wall_by_face(t_game *game, int i, int size)
{
	if (game->ray.last_move == 'y' && game->ray.step.y < 0)
		return (pipette_color_from_img(&game->art.north,
				set_pixel((int)map_double(game->ray.hit_point, 1,
						game->art.north.width),
					map_int(i, size, game->art.north.height))));
	else if (game->ray.last_move == 'y' && game->ray.step.y > 0)
		return (pipette_color_from_img(&game->art.south,
				set_pixel((int)map_double(game->ray.hit_point, 1,
						game->art.south.width),
					map_int(i, size, game->art.south.height))));
	else if (game->ray.last_move == 'x' && game->ray.step.x < 0)
		return (pipette_color_from_img(&game->art.west,
				set_pixel((int)map_double(game->ray.hit_point, 1,
						game->art.west.width),
					map_int(i, size, game->art.west.height))));
	else if (game->ray.last_move == 'x' && game->ray.step.x > 0)
		return (pipette_color_from_img(&game->art.east,
				set_pixel((int)map_double(game->ray.hit_point, 1,
						game->art.east.width),
					map_int(i, size, game->art.east.height))));
	return (0);
}

static void	_wall_in_range(t_game *game, t_ray *ray, int size, int start_y)
{
	int	i;

	i = 0;
	while (i < size)
	{
		draw_pixel_to_img(
			&game->scene,
			set_pixel(ray->camera_x, start_y + i),
			_pipette_wall_by_face(game, i, size));
		i++;
	}
}

static void	_wall_out_range(t_game *game, t_ray *ray, double distance)
{
	int		i;
	double	normal_texture_start;
	double	normal_texture_end;
	double	normal_texture_size;
	double	step;

	i = 0;
	normal_texture_start = distance
		* ((double)-WIN_H / 2.0) + (double)WIN_H / 2.0;
	normal_texture_size = ((double)WIN_H / 2.0 - normal_texture_start) * 2.0;
	normal_texture_end = normal_texture_start + normal_texture_size;
	step = (normal_texture_end - normal_texture_start) / WIN_H;
	while (i < WIN_H)
	{
		draw_pixel_to_img(&game->scene, set_pixel(ray->camera_x, i),
			_pipette_wall_by_face(game,
				normal_texture_start + step * i, WIN_H));
		i++;
	}
}

void	render_game_scene_line_wall(t_game *game,
t_ray *ray, double distance, int start_y)
{
	if (game->ray.last_move == 'y' && game->ray.step.y > 0)
		game->ray.hit_point = 1 - game->ray.hit_point;
	else if (game->ray.last_move == 'x' && game->ray.step.x < 0)
		game->ray.hit_point = 1 - game->ray.hit_point;
	if (distance >= 1)
		_wall_in_range(game, ray, 1 / distance * WIN_H, start_y);
	else
	{
		_wall_out_range(game, ray, distance);
	}
}
