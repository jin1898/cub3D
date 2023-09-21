/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:37:56 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 03:20:09 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_hand(t_game *game)
{
	if (game->hook.state_mouse_left == TRUE)
		mlx_put_image_to_window(game->mlx, game->win, game->art.hand_shoot.img,
			WIN_W - 525, WIN_H - 300);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->art.hand_idle.img,
			WIN_W - 525, WIN_H - 300);	
}