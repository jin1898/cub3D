/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/22 21:29:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_cub3d(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		return (FAILURE);
	ft_memset(game, 0, sizeof(*game));
	game->argv = argv;
	if (init_cub3d_parse(game) == FAILURE)
		return (FAILURE);
	/* if (map_validation(game->map) == FAILURE)
		return (FAILURE); *///여기에 dfs bfs 검사하는부분
	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (load_images(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
