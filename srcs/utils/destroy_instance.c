/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:32:57 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/15 17:53:50 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	destroy_instance(t_game *game)
{
	if (game->art.north.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.north.img);
	if (game->art.south.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.south.img);
	if (game->art.west.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.west.img);
	if (game->art.east.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->art.east.img);
	if (game->scene.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->scene.img);
	if (game->mini.img != NULL && game->mlx != NULL)
		mlx_destroy_image(game->mlx, game->mini.img);
	if (game->mlx != NULL && game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	return (SUCCESS);
}
