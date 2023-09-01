/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/01 19:21:01 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*------DFS------start-------*/
int	check_map(char **map, size_t x, size_t y)
{
	int	g_dirx[8] = {-1, 0, 1, 0}; //서, 남, 동, 북, 북서, 남서, 남동, 북동
	int	g_diry[8] = {0, 1, 0, -1};
	int i;

	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == '3')	//공백을 만나 0 return
		return (0);
	map[y][x] = 'x';	//이미 방문한 곳은 x로 체크
	printf("[%zd %zd], %c\n",y,x,map[y][x]);
	ft_print_dfs_CurrentSituation(map); // 지워야함
	/* 0을 만나 함수를 재귀 호출 */
	i = -1;
	while (++i < 4)
		if (check_map(map, x + g_dirx[i], y + g_diry[i]) == 0) //g_dirx와 g_diry로 8방향 이동
			return (0);
	return (1);
}
int	get_x(char **map)
{
	int i = 0;
	int count = 2;
	while(map[i])
	{
		count++;
		i++;
	}
	return(count);
}

int get_y(char **map)
{
	int largest = 0;
	int x = 0;
	int y = 0;
	int count = 2;
	while(map[x])
	{
		while(map[x][y])
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
	return(largest);
}
char	**init_map(char **map, t_game *game)
{
	size_t		x;
	size_t		y;
	char	**test_map;

	/* 테두리 공간을 확보하기 위해 가로,세로가 2씩 큰 맵 생성 */
	game->map_x = get_x(map);
	if (!(test_map = (char **)malloc(sizeof(char *) * (game->map_x + 1))))
		return (0);
	test_map[game->map_x] = 0;	//null
	y = -1;
	game->map_y = get_y(map);
	while (++y < game->map_x)
	{
		if (!(test_map[y] = (char *)malloc(sizeof(char) * (game->map_y + 1))))
			return (0);
		test_map[y][game->map_y] = 0;	//null
		x = -1;
		while (++x < game->map_y)
			test_map[y][x] = '3';	//공백으로 채움
	}
	printf("test_map\n");
	ft_print_dfs_CurrentSituation(test_map);
	/* 테두리는 공백으로 남겨두고, (1, 1)부터 map데이터를 채움 */
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			test_map[y + 1][x + 1] = map[y][x];
	}
	printf("\n\ntest_map fill complete\n");
	ft_print_dfs_CurrentSituation(test_map);
	return (test_map);
}

/* int		free_map(char **map, size_t cnt)
{
	while (1)
	{
		free(map[cnt]);
		cnt--;
		if(cnt == 0)
		{
			free(map[cnt]);
			break;
		}
	}
	free(map);
	return (0);
} */

static int	_is_surround(char **map, t_game *game)
{
	char	**test_map;
	int		isMap_empty;
	int		x;
	int		y;

	isMap_empty = 0;
	y = -1;
	test_map = init_map(map, game);
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
		{
			if (test_map[y][x] == '0')	//'0'을 만나면 검사 시작
			{
				isMap_empty = 1;
				if (check_map(test_map, x, y) == 0)
				{
					free_split(test_map);
					return(FAILURE);
				}
			}
		}
	}
	free_split(test_map);
	if (isMap_empty == 0)
		return(FAILURE);
	return(SUCCESS);
}//bfs/dfs 본격 몸통부분
/*------DFS------end-------*/

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
	if(_is_surround(game->map, game))
		return (FAILURE);
	return (SUCCESS);
}// bfs/dfs 할려고 했음.(헤드부분)
