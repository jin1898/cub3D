/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_dfs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:41 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/09/06 15:11:20 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_longest_x(char **map)
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

void	copy_map(char **map, char **test_map)
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

int	check_map_four_directions(char **map, size_t x, size_t y)
{
	int	dir_x[4];
	int	dir_y[4];
	int	i;

	dir_x[0] = -1;
	dir_x[1] = 0;
	dir_x[2] = 1;
	dir_x[3] = 0;

	dir_y[0] = 0;
	dir_y[1] = 1;
	dir_y[2] = 0;
	dir_y[3] = -1;

	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == '3')
		return (0);
	map[y][x] = 'x';
	i = -1;
	while (++i < 4)
		if (check_map_four_directions(map, x + dir_x[i], y + dir_y[i]) == 0)
			return (0);
	return (1);
}

static int	_is_correct_map(size_t x, size_t y,
int *ismap_empty, char **test_map)
{
	*ismap_empty = 1;
	if (check_map_four_directions(test_map, x, y) == 0)
	{
		free_split(test_map);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	is_surround(char **map, t_game *game)
{
	char		**test_map;
	int			ismap_empty;
	size_t		x;
	size_t		y;

	ismap_empty = 0;
	y = -1;
	test_map = init_map(map, game);
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
		{
			if (test_map[y][x] == '0')
			{
				if (_is_correct_map(x, y, &ismap_empty, test_map)
					== FAILURE)
					return (FAILURE);
			}
		}
	}
	free_split(test_map);
	if (ismap_empty == 0)
		return (FAILURE);
	return (SUCCESS);
}
