/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:17:34 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/15 17:50:10 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_xpm_file_to_component(t_game *game, t_component *comp, char *path)
{
	int	x;
	int	y;

	comp->img = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
	if (comp->img == NULL)
		return ;
	comp->width = x;
	comp->height = y;
	comp->mlx_data_addr = (int *)mlx_get_data_addr(comp->img, &comp->bpp,
			&comp->line_size, &comp->endian);
}

void	load_images_texture(t_game *game, t_art *art)
{
	_xpm_file_to_component(game, &art->north, game->north_path);
	_xpm_file_to_component(game, &art->south, game->south_path);
	_xpm_file_to_component(game, &art->west, game->west_path);
	_xpm_file_to_component(game, &art->east, game->east_path);
}
