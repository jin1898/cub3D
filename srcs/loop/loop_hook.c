/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:21:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/16 18:52:01 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	loop_hook(t_game *game)
{
	game->hook.loop_hook_term++;
	if (game->hook.loop_hook_term == 30)
	{
		reset_vector(game, game->hook, game->map);
		render_game_scene(game);
		render_cross_hair(game);
		render_mini_map(game);
		mlx_put_image_to_window(game->mlx, game->win, game->scene.img, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
			WIN_W - game->mini.width - 20, WIN_H - game->mini.height - 20);
		mlx_put_image_to_window(game->mlx, game->win, game->abc, 0, 0);
		game->hook.loop_hook_term = 0;
	}
	return (0);
}
