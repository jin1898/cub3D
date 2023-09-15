/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:21:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/16 01:40:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	loop_hook(t_game *game)
{
	game->hook.loop_hook_term++;
	if (game->hook.loop_hook_term == 3)
	{
		reset_vector(game, game->hook, game->map);
		render_game_scene(game);
		render_mini_map(game);
		game->hook.loop_hook_term = 0;
	}
	return (0);
}
