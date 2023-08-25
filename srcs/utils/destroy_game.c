/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:32:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/25 15:38:10 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	destroy_game(t_game *game)
{
	if (game->art.north != NULL)
		mlx_destroy_image(game->mlx, game->art.north);
	if (game->art.south != NULL)
		mlx_destroy_image(game->mlx, game->art.south);
	if (game->art.west != NULL)
		mlx_destroy_image(game->mlx, game->art.west);
	if (game->art.east != NULL)
		mlx_destroy_image(game->mlx, game->art.east);
	if (game->mlx != NULL && game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	return (SUCCESS);
}