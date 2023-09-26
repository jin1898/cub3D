/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:32:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/22 19:28:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_destroy_component(t_component *comp, t_game *game)
{
	if (comp->img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, comp->img);
}

int	destroy_instance(t_game *game)
{
	_destroy_component(&game->art.ammo, game);
	_destroy_component(&game->art.hand_idle, game);
	_destroy_component(&game->art.hand_shoot, game);
	_destroy_component(&game->art.hand_reload_1, game);
	_destroy_component(&game->art.hand_reload_2, game);
	_destroy_component(&game->art.mouse_cursor, game);
	_destroy_component(&game->art.title_menu, game);
	_destroy_component(&game->art.north, game);
	_destroy_component(&game->art.south, game);
	_destroy_component(&game->art.west, game);
	_destroy_component(&game->art.east, game);
	if (game->scene.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->scene.img);
	if (game->mini.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->mini.img);
	if (game->mlx != NULL && game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	return (SUCCESS);
}
