/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:43:49 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 14:51:30 by jeekpark         ###   ########.fr       */
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
	else if (keycode == KEY_R)
		game->hook.state_key_r = TRUE;
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}
