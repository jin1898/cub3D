/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/27 20:38:43 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void ft_print_dfs_CurrentSituation(char ** map) // 지워야함
{
	int x = 0;
	int y = 0;

	printf("\n --start---- \n");
	while (map[x])
	{
		printf("[x : %d] : ", x);
		while(map[x][y])
		{
			printf("[%c] ", map[x][y]);
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
	printf("\n --end---- \n");
}

static void	get_move(int *x, int *y, int i)//위 , 왼쪽, 아래 , 오른쪽 (시계반대방향)
{
	if (i == 0)
		*x += 1;
	else if (i == 1)
		*y += -1;
	else if (i == 2)
		*x += -1;
	else if (i == 3)
		*y += 1;
	return ;
}

static int	ft_move(char **map, int x, int y, int i)
{
	if (i == 0)
		x += 1;
	else if (i == 1)
		y += -1;
	else if (i == 2)
		x += -1;
	else if (i == 3)
		y += 1;
	return (map[x][y]);
}

static int	_is_surround(char **map, int x, int y)
{
	int	i;
	int	result;

	i = 0;
	while (i < 4)
	{
		ft_print_dfs_CurrentSituation(map);
		result = ft_move(map, x, y, i);
		if (result == '0' || result == 'N' || result == 'S' || result == 'W' || result == 'E')
		{
			if (map[x][y] == '0')
				map[x][y] = '2';
			get_move(&x, &y, i);
			_is_surround(map, x, y);
		}
		else if (result != '1' && result != '2')
			return (1);
		if(map[x][y] == '0')
			map[x][y] = '2';
		i++;
	}
	return(0);
}//bfs/dfs 본격 몸통부분

static void	_set_player(int x, int y, char dir, t_game *game)
{//문제발생 N S W는 있는데 E는??
	game->player_pos.x = x;
	game->player_pos.y = y;
	if (dir == 'N')
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

	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'W' || map[x][y] == 'E')
				{
					_set_player(x, y, map[y][x], game);
					res++;
				}
			y++;
		}
		x++;
		y = 0;
	}
	return (res);
}//주인공이몇명인지 체크

int	map_validation(t_game *game)
{
	if (_player_count(game->map, game) != 1)
		return (FAILURE);
	if(_is_surround(game->map, game->player_pos.x, game->player_pos.y))
		return (FAILURE);
	return (SUCCESS);
}// bfs/dfs 할려고 했음.(헤드부분)
