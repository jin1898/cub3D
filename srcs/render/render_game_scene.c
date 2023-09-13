/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:10:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/13 18:54:48 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_render_line(t_component *comp, double distance, int camera_x, int face)
{
	int	i;
	int	size;
	int	start_y;
	int	end_y;
	int	color;

	if (face == 1)
		color = rgb8_to_int(255, 0, 0);
	else if (face == 2)
		color = rgb8_to_int(0, 255, 0);
	else if (face == 3)
		color = rgb8_to_int(0, 0, 255);
	else if (face == 4)
		color = rgb8_to_int(255, 255, 255);
	else
		color = rgb8_to_int(0,0,0);
	size = 1 / distance * (WIN_H);
	start_y = (WIN_H/2) - (size/2);
	end_y = start_y + size;
	for (;start_y < end_y; start_y++)
	{
		draw_pixel_to_img(comp, set_pixel(camera_x, start_y), color);
	}
}

void	render_game_scene(t_game *game)
{
	int		camera_x;
	double	step_degree;
	int 	face;
	draw_rect_to_img(&game->scene, set_pixel(0, 0), set_pixel(WIN_W-1, WIN_H-1 / 2), game->ceiling_color);
	draw_rect_to_img(&game->scene, set_pixel(0, WIN_H/2), set_pixel(WIN_W-1, WIN_H-1), game->floor_color);
	
	face = 0;
	camera_x = 0;
	step_degree = (double)120 / (double)WIN_W;
	while (camera_x < WIN_W)
	{
		t_vector	ray = {
			game->view_angle.x + game->plane_angle.x *(2 * camera_x / (double)WIN_W - 1),
			game->view_angle.y + game->plane_angle.y *(2 * camera_x / (double)WIN_W - 1)
		};
		
		double dist = ray_casting(
			game,
			game->player,
			ray,
			&face
		);
		
		_render_line(
			&game->scene,
			dist,	
			camera_x,
			face
		);

		camera_x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->scene.img,
		0,0);
	return ;
}
/* t_vector	ray = {
			game->view_angle.x + game->plane_angle.x *(2 * camera_x / (double)WIN_W - 1),
			game->view_angle.y + game->plane_angle.y *(2 * camera_x / (double)WIN_W - 1)
		}; */