/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 14:50:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_load_images_game_scene(t_game *game, t_component *scene)
{
	scene->width = WIN_W;
	scene->height = WIN_H;
	scene->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (scene->img == NULL)
		return ;
	scene->mlx_data_addr = (int *)mlx_get_data_addr(scene->img, &scene->bpp,
			&scene->line_size, &scene->endian);
}

static void	_reset_mini_map_tile_size(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) > game->mini_map_tile_size)
			game->mini_map_tile_size = ft_strlen(game->map[i]);
		i++;
	}
	if (i > game->mini_map_tile_size)
		game->mini_map_tile_size = i;
	game->mini_map_tile_size = game->mini.width / game->mini_map_tile_size;
}

static void	_load_images_mini_map(t_game *game, t_component *mini)
{
	mini->width = WIN_W / 6.4;
	mini->height = mini->width;
	mini->img = mlx_new_image(game->mlx, mini->width, mini->height);
	if (mini->img == NULL)
		return ;
	mini->mlx_data_addr = (int *)mlx_get_data_addr(mini->img, &mini->bpp,
			&mini->line_size, &mini->endian);
	_reset_mini_map_tile_size(game);
}

int	load_images(t_game *game)
{
	load_images_texture(game, &game->art);
	_load_images_mini_map(game, &game->mini);
	_load_images_game_scene(game, &game->scene);
	if (game->art.north.img == NULL || game->art.south.img == NULL
		|| game->art.west.img == NULL || game->art.east.img == NULL
		|| game->mini.img == NULL || game->scene.img == NULL
		|| game->art.hand_idle.img == NULL
		|| game->art.hand_shoot.img == NULL
		|| game->art.ammo.img == NULL
		|| game->art.title_menu.img == NULL
		|| game->art.mouse_cursor.img == NULL
		|| game->art.hand_reload_1.img == NULL
		|| game->art.hand_reload_2.img == NULL)
		return (FAILURE);
	return (SUCCESS);
}
