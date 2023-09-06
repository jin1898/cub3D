/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:32:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/06 13:43:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	destroy_instance(t_game *game)
{
	if (game->art.north != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.north);
	if (game->art.south != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.south);
	if (game->art.west != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.west);
	if (game->art.east != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.east);
	if (game->mlx != NULL && game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	return (SUCCESS);
}
