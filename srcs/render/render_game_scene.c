/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:10:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/11 17:20:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_render_line(t_component *comp, double distance, int camera_x)
{
	int	i;
	int	size;
	int	start_y;

	size = 1 / distance * (WIN_H);
	start_y = (WIN_H/2) - (size/2);
	draw_line_to_img(comp,
		set_pixel(camera_x, start_y),
		set_pixel(camera_x, start_y + size),
		rgb8_to_int(255, 255, 255));
}

void	render_game_scene(t_game *game)
{
	int	camera_x;

	camera_x = 0;
	while (camera_x < WIN_W)
	{
		_render_line(&game->scene,
			ray_casting(game->map,
				game->player,
				rotate_vector(game->view_angle, -60 + (camera_x * 120 / WIN_H))),
			camera_x);
		camera_x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->scene.img,
		0,0);
	return ;
}
