/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:21:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/22 23:08:41 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_render_images(t_game *game)
{
	render_game_scene(game);
	render_mini_map(game);
	render_hand(game);
}

int	loop_hook(t_game *game)
{
	game->hook.loop_hook_term++;
	if (game->hook.loop_hook_term == 30)
	{
		reset_vector(game, game->hook, game->map);
		_render_images(game);
		game->hook.loop_hook_term = 0;
	}
	return (0);
}
