/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/03 16:44:58 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_load_game_screen_image(t_game *game, t_component *screen)
{
	screen->width = WIN_W;
	screen->height = WIN_H;
	screen->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (screen->img == NULL)
		return ;
	screen->mlx_data_addr = (int *)mlx_get_data_addr(screen->img,
			&screen->bpp, &screen->line_size, &screen->endian);
}

static void	_reset_mini_map_tile_scale(t_game *game)
{
	size_t i;
	
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) > game->mini_map_tile_scale)
			game->mini_map_tile_scale = ft_strlen(game->map[i]);
		i++;
	}
	if (i > game->mini_map_tile_scale)
		game->mini_map_tile_scale = i;
	game->mini_map_tile_scale = game->mini.width / game->mini_map_tile_scale;
}

static void	_load_mini_map_image(t_game *game, t_component *mini)
{
	mini->width = WIN_W / 6.4;
	mini->height = mini->width;
	mini->img = mlx_new_image(game->mlx, mini->width, mini->height);
	if (mini->img == NULL)
		return ;
	mini->mlx_data_addr = (int *)mlx_get_data_addr(mini->img, &mini->bpp,
			&mini->line_size, &mini->endian);
	_reset_mini_map_tile_scale(game);
}

int	load_images(t_game *game)
{
	int	x;
	int	y;

	game->art.north = mlx_xpm_file_to_image(game->mlx,
			game->north_path, &x, &y);
	game->art.south = mlx_xpm_file_to_image(game->mlx,
			game->south_path, &x, &y);
	game->art.west = mlx_xpm_file_to_image(game->mlx,
			game->west_path, &x, &y);
	game->art.east = mlx_xpm_file_to_image(game->mlx,
			game->east_path, &x, &y);
	_load_mini_map_image(game, &game->mini);
	_load_game_screen_image(game, &game->screen);
	if (game->art.north == NULL || game->art.south == NULL
		|| game->art.west == NULL || game->art.west == NULL
		|| game->mini.img == NULL || game->screen.img == NULL)
		return (FAILURE);
	return (SUCCESS);
}
