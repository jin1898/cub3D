/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:21:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/06 15:21:59 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	loop_hook(t_game *game)
{
	reset_vector(game, game->hook, game->map);
	render_game_scene(game);
	render_mini_map(game);
	return (0);
}
