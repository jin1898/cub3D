/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:32:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/22 20:49:34 by jeekpark         ###   ########.fr       */
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
	mlx_destroy_window(game->mlx, game->win);
	return (SUCCESS);
}