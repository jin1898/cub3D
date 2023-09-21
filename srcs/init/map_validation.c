/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/18 23:10:09 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_set_player(int x, int y, char dir, t_game *game)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	if (dir == 'N')
		game->view_angle.y = -1;
	else if (dir == 'S')
		game->view_angle.y = 1.0001;
	else if (dir == 'W')
		game->view_angle.x = -1;
	else
		game->view_angle.x = 1;
	game->plane_angle = rotate_vector(game->view_angle, 90);
}

static int	_player_count(char **map, t_game *game)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	y = 0;
	res = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				_set_player(x, y, map[y][x], game);
				res++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (res);
}

int	map_validation(t_game *game)
{
	if (_player_count(game->map, game) != 1)
		return (FAILURE);
	if (map_validation_is_surround(game->map, game))
		return (FAILURE);
	return (SUCCESS);
}
