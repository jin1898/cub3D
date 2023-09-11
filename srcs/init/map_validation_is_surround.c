/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_is_surround.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:02:36 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/09/11 15:50:35 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_copy_map(char **map, char **test_map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			test_map[y + 1][x + 1] = map[y][x];
	}
}

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

static int	_find_longest_x(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 2;
	while (map[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	**_init_map(char **map, t_game *game)
{
	size_t	x;
	size_t	y;
	char	**test_map;

	game->map_x = _find_longest_x(map);
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
	_copy_map(map, test_map);
	return (test_map);
}

int	map_validation_is_surround(char **map, t_game *game)
{
	char		**test_map;
	int			is_map_empty;
	size_t		x;
	size_t		y;

	is_map_empty = 0;
	y = -1;
	test_map = _init_map(map, game);
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
		{
			if (test_map[y][x] == '0' || test_map[y][x] == 'N' || test_map[y][x]
				== 'E' || test_map[y][x] == 'W' || test_map[y][x] == 'S')
				if (map_validation_dfs(x, y, &is_map_empty, test_map)
					== FAILURE)
					return (FAILURE);
		}
	}
	free_split(test_map);
	if (is_map_empty == 0)
		return (FAILURE);
	return (SUCCESS);
}
