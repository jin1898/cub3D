/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:46 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/05 15:13:03 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_load_game_scene_image(t_game *game, t_component *scene)
{
	scene->width = WIN_W;
	scene->height = WIN_H;
	scene->img = mlx_new_image(game->mlx, WIN_W, WIN_H); //창이 아니라 이미지 만듬.
	if (scene->img == NULL)
		return ;
	scene->mlx_data_addr = (int *)mlx_get_data_addr(scene->img, &scene->bpp,
		&scene->line_size, &scene->endian);
}

static void	_reset_mini_map_tile_size(t_game *game)//미니맵을 그릴때 가로가 큰지 세로가 큰지 판별후 해당 길이를 미니맵사이즈로 나눠 한타일의 크기를 알아내고 리턴
{
	size_t i;
	
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

static void	_load_mini_map_image(t_game *game, t_component *mini)
{
	mini->width = WIN_W / 6.4;
	mini->height = mini->width;
	mini->img = mlx_new_image(game->mlx, mini->width, mini->height);// 빈 이미지 인스턴스를 만든다.
	if (mini->img == NULL)
		return ;
	mini->mlx_data_addr = (int *)mlx_get_data_addr(mini->img, &mini->bpp,
			&mini->line_size, &mini->endian);
	_reset_mini_map_tile_size(game);
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
	_load_mini_map_image(game, &game->mini); // 미니맵 이미지(mimimap) 만드는 함수
	_load_game_scene_image(game, &game->scene);// 3D 이미지(game scene) 만드는 함수
	if (game->art.north == NULL || game->art.south == NULL
		|| game->art.west == NULL || game->art.west == NULL
		|| game->mini.img == NULL || game->scene.img == NULL)
		return (FAILURE);
	return (SUCCESS);
}
