/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:10:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/16 00:07:07 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_game_scene(t_game *game)
{
	game->ray.camera_x = 0;
	while (game->ray.camera_x < WIN_W)
	{
		game->ray.dir = set_vector(
				game->view_angle.x + game->plane_angle.x
				*(2 * game->ray.camera_x / (double)WIN_W - 1),
				game->view_angle.y + game->plane_angle.y
				* (2 * game->ray.camera_x / (double)WIN_W - 1));
		render_game_scene_line(
			game,
			ray_casting(game, &game->ray, game->player, game->ray.dir));
		game->ray.camera_x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->scene.img, 0, 0);
}
