/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:21:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/18 22:09:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_render_images(t_game *game)
{
	render_game_scene(game);
	render_cross_hair(game);
	render_mini_map(game);
}

void	_image_to_window(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->scene.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
		WIN_W - game->mini.width - 20, WIN_H - game->mini.height - 20);
}

int	loop_hook(t_game *game)
{
	game->hook.loop_hook_term++;
	if (game->hook.loop_hook_term == 30)
	{
		reset_vector(game, game->hook, game->map);
		_render_images(game);
		_image_to_window(game);
		game->hook.loop_hook_term = 0;
	}
	return (0);
}
