/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_dfs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:41 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/09/26 21:58:24 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_check_map_four_directions(char **map, size_t x, size_t y)
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
	if (map[y][x] == '3' || map[y][x] == ' ')
		return (0);
	map[y][x] = 'x';
	i = -1;
	while (++i < 4)
		if (_check_map_four_directions(map, x + dir_x[i], y + dir_y[i]) == 0)
			return (0);
	return (1);
}

static int	_check_smallest_map(size_t x, size_t y, char **map)
{
	if (map[y + 1][x] == '1'
		&& map[y - 1][x] == '1'
		&& map[y][x + 1] == '1'
		&& map[y][x - 1] == '1')
		return (SUCCESS);
	return (FAILURE);
}

int	map_validation_dfs(size_t x, size_t y,
int *is_map_empty, char **test_map)
{
	*is_map_empty = 1;
	if (_check_map_four_directions(test_map, x, y) == 0)
	{
		if (_check_smallest_map(x, y, test_map) == SUCCESS)
			return (SUCCESS);
		free_split(test_map);
		return (FAILURE);
	}
	return (SUCCESS);
}
