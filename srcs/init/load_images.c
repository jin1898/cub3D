/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/22 18:50:42 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int load_images(t_game *game)
{
	int x;
	int	y;

	x = 64;
	y = 64;
	printf("123\n");
	game->art.north = mlx_xpm_file_to_image(game->mlx,
		game->north_path, &x, &y);
	game->art.south = mlx_xpm_file_to_image(game->mlx,
		game->south_path, &x, &y);
	game->art.west = mlx_xpm_file_to_image(game->mlx,
		game->west_path, &x, &y);
	game->art.east = mlx_xpm_file_to_image(game->mlx,
		game->east_path, &x, &y);
	printf("123\n");
	if (game->art.north == NULL || game->art.south == NULL
		|| game->art.west == NULL || game->art.west == NULL)
		return (FAILURE);
	return (SUCCESS);
	
}
