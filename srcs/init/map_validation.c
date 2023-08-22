/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/22 21:19:00 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_is_surround(char **map, t_vector *pos)
{
	
}//bfs/dfs 본격 몸통부분

static void	_set_player(int x, int y, char dir, t_game *game)
{
	game->player_pos.x = x;
	game->player_pos.y = y;
	if (dir = 'N')
		game->player_dir.y = -1;
	else if (dir == 'S')
		game->player_dir.y = 1;
	else if (dir == 'W')
		game->player_dir.x = -1;
	else
		game->player_dir.x = 1;
}//시야방향과 현재 좌표 저장하는부분

static int	_player_count(char **map, t_game *game)
{
	int	x;
	int y;
	int res;

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
}//주인공이몇명인지 체크

int	map_validation(t_game *game)
{
	if (_player_count(game->map, game) != 1)
		return (FAILURE);
	
}// bfs/dfs 할려고 했음.(헤드부분)