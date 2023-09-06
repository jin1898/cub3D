/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:43:49 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/05 19:29:58 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->hook.state_key_a = TRUE;
	else if (keycode == KEY_W)
		game->hook.state_key_w = TRUE;
	else if (keycode == KEY_D)
		game->hook.state_key_d = TRUE;
	else if (keycode == KEY_S)
		game->hook.state_key_s = TRUE;
	else if (keycode == KEY_RIGHT)
		game->hook.state_key_right = TRUE;
	else if (keycode == KEY_LEFT)
		game->hook.state_key_left = TRUE;
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}


/* game->view_angle = rotate_vector(game->view_angle, -10);
		game->plane_angle = rotate_vector(game->view_angle, 90);
		t_vector	plane_center = add_vector(game->player, game->view_angle);
		draw_rect_to_img(
			&game->scene,
			set_pixel(0, 0),
			set_pixel(WIN_W, WIN_H),
			rgb8_to_int(0,0,0)
		);
		draw_line_to_img(
			&game->scene, 
			set_pixel(plane_center.x, plane_center.y),
			set_pixel(game->player.x, game->player.y),
			rgb8_to_int(255,255, 255)
		);
		mlx_put_image_to_window(game->mlx, game->win, game->scene.img, 0, 0); */