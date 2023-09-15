/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:56 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/16 02:08:52 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	if (y < 0 || y > WIN_H - 1)
		mlx_mouse_move(game->win, x, WIN_H / 2);
	if (ft_abs(game->hook.prev_mouse_x - x) >= (WIN_W / 2))
		game->view_angle = rotate_vector(game->view_angle,
				-(45 / (double)(WIN_W / 2))
				* (ft_abs(game->hook.prev_mouse_x - x) - (WIN_W / 2)));
	else
		game->view_angle = rotate_vector(game->view_angle,
				-(45 / (double)(WIN_W / 2))
				* (game->hook.prev_mouse_x - x));
	game->plane_angle = rotate_vector(game->view_angle, 90);
	if (x < 0 || x > WIN_W - 1)
	{
		mlx_mouse_move(game->win, WIN_W / 2, y);
		game->hook.prev_mouse_x = WIN_W / 2;
	}
	else
		game->hook.prev_mouse_x = x;
	return (0);
}
