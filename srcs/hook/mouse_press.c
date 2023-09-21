/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:53:00 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 03:09:47 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_press(int keycode, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_LEFT)
	{
		if (game->ammo_count > 0)
			game->ammo_count--;
		game->hook.state_mouse_left = TRUE;
	}
	return (0);
}