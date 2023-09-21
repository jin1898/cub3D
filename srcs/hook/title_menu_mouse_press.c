/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_menu_mouse_press.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:31:35 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 14:51:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	title_menu_mouse_press(int keycode, int x, int y, t_game *game)
{
	if (keycode == MOUSE_LEFT
		&& (x > 100 && x < 280)
		&& (y > 360 && y < 410))
	{
		mlx_mouse_move(game->win, WIN_W / 2, WIN_H / 2);
		mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, key_press, game);
		mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, key_release, game);
		mlx_hook(game->win, X_EVENT_MOUSE_PRESS, 0, mouse_press, game);
		mlx_hook(game->win, X_EVENT_MOUSE_RELEASE, 0, mouse_release, game);
		mlx_hook(game->win, X_EVENT_MOTION_NOTIFY, 0, mouse_move, game);
		mlx_loop_hook(game->mlx, loop_hook, game);
		game->ammo_count = 9;
	}
	else if (keycode == MOUSE_LEFT
		&& (x > 100 && x < 157)
		&& (y > 480 && y < 518))
	{
		exit_game(game);
	}
	return (0);
}
