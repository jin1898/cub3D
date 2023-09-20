/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:47:01 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/18 21:49:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->hook.state_key_a = FALSE;
	else if (keycode == KEY_W)
		game->hook.state_key_w = FALSE;
	else if (keycode == KEY_D)
		game->hook.state_key_d = FALSE;
	else if (keycode == KEY_S)
		game->hook.state_key_s = FALSE;
	else if (keycode == KEY_RIGHT)
		game->hook.state_key_right = FALSE;
	else if (keycode == KEY_LEFT)
		game->hook.state_key_left = FALSE;
	return (0);
}
