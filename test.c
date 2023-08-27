#include <stdio.h>
#include <stdlib.h>

int	g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; //서, 남, 동, 북, 북서, 남서, 남동, 북동
int	g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};


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

/* 완전 탐색으로 맵을 검사한다 */
int	check_map(char **map, int x, int y)
{
	int i;
	printf("[i am in check_map!]\n");
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] != '1' || map[y][x] != '0' || map[y][x] != 'x')	//공백을 만나 0 return
		return (0);
	map[y][x] = 'x';	//이미 방문한 곳은 x로 체크

	/* 0을 만나 함수를 재귀 호출 */
	i = -1;
	while (++i < 8)
		if (check_map(map, x + g_dirx[i], y + g_diry[i]) == 0) //g_dirx와 g_diry로 8방향 이동
			return (0);
	return (1);
}

int		free_map(char **map, int cnt)
{
	while (cnt >= 0)
	{
		free(map[cnt]);
		cnt--;
	}
	free(map);
	return (0);
}

int	main()
{
	int		x, y;
	int		is_zero;
	char	**map;

	/* 예시 문제 */
	if (!(map = (char **)malloc(sizeof(char *) * 3)))
		return (0);
	map[0] = "1111111";
	map[1] = "1000001";
	map[2] = "1111111";

	/* 테스트 시작 */
	printf("1\n");
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			printf("main: x : %d | y : %d\n",x,y);
			if (map[x][y] == '0')	//'0'을 만나면 검사 시작
			{
				is_zero = 1;
				if (check_map(map, x, y) == 0)
				{
					printf("ERROR\n");
					printf("끝났음 x : %d\n",x);
					return (0) ;
				}
			}
			ft_print_dfs_CurrentSituation(map);
		}
	}
	printf("끝났음 x : %d\n",x);
	if (is_zero == 0)
		printf("ERROR\n");
	else
		printf("OK\n");
	// free_map(map, 103);
	return (0);
}

// https://sewcode.tistory.com/11
