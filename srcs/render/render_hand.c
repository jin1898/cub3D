/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:37:56 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 14:59:46 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_hand(t_game *game)
{
	if (game->hook.state_key_r == TRUE)
	{
		if (game->reload_time == 20)
		{
			game->reload_time = 0;
			game->ammo_count = 9;
			game->hook.state_key_r = FALSE;
			return ;
		}
		if (game->reload_time < 10)
			mlx_put_image_to_window(game->mlx, game->win,
				game->art.hand_reload_1.img, WIN_W - 525, WIN_H - 300);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->art.hand_reload_2.img, WIN_W - 525, WIN_H - 300);
		(game->reload_time)++;
	}
	else if (game->hook.state_mouse_left == TRUE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->art.hand_shoot.img, WIN_W - 525, WIN_H - 300);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->art.hand_idle.img, WIN_W - 525, WIN_H - 300);
}
