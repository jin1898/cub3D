/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:56 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/22 19:33:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	game->view_angle
		= rotate_vector(game->view_angle, (x - (WIN_W / 2)) * MOUSE_SPEED);
	game->plane_angle = rotate_vector(game->view_angle, 90);
	mlx_mouse_move(game->win, WIN_W / 2, WIN_H / 2);
	return (SUCCESS);
}
