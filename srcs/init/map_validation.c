/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/09 19:44:46 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_find_longest_y(char **map)
{
	int	largest;
	int	x;
	int	y;
	int	count;

	largest = 0;
	x = 0;
	y = 0;
	count = 2;
	while (map[x])
	{
		while (map[x][y])
		{
			count++;
			y++;
		}
		if (count > largest)
			largest = count;
		y = 0;
		count = 2;
		x++;
	}
	return (largest);
}

static void	_set_player(int x, int y, char dir, t_game *game)
{
	game->player.x = x;
	game->player.y = y;
	if (dir == 'N')
		game->view_angle.y = -1;
	else if (dir == 'S')
		game->view_angle.y = 1;
	else if (dir == 'W')
		game->view_angle.x = -1;
	else
		game->view_angle.x = 1;
	if (dir == 'N')
		game->plane_angle.x = 1;
	else if (dir == 'S')
		game->plane_angle.x = -1;
	else if (dir == 'W')
		game->plane_angle.y = -1;
	else
		game->plane_angle.y = 1;
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

char	**init_map(char **map, t_game *game)
{
	size_t	x;
	size_t	y;
	char	**test_map;

	game->map_x = find_longest_x(map);
	test_map = (char **)malloc(sizeof(char *) * (game->map_x + 1));
	if (!test_map)
		return (0);
	test_map[game->map_x] = 0;
	y = -1;
	game->map_y = _find_longest_y(map);
	while (++y < game->map_x)
	{
		test_map[y] = (char *)malloc(sizeof(char) * (game->map_y + 1));
		if (!test_map[y])
			return (0);
		test_map[y][game->map_y] = 0;
		x = -1;
		while (++x < game->map_y)
			test_map[y][x] = '3';
	}
	copy_map(map, test_map);
	return (test_map);
}

int	map_validation(t_game *game)
{
	if (_player_count(game->map, game) != 1)
		return (FAILURE);
	if (is_surround(game->map, game))
		return (FAILURE);
	return (SUCCESS);
}
