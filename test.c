#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
	int x_num;
}t_a;
/*
int	g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; //서, 남, 동, 북, 북서, 남서, 남동, 북동
int	g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};

// 완전 탐색으로 맵을 검사한다
int	check_map(char **map, int x, int y)
{
	int i;
	printf("[i am in check_map!]\n");
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] != '1' || map[y][x] != '0' || map[y][x] != 'x')	//공백을 만나 0 return
		return (0);
	map[y][x] = 'x';	//이미 방문한 곳은 x로 체크

	//  0을 만나 함수를 재귀 호출
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

	// 예시 문제
	if (!(map = (char **)malloc(sizeof(char *) * 3)))
		return (0);
	map[0] = "1111111";
	map[1] = "1000001";
	map[2] = "1111111";

	// 테스트 시작
	printf("1\n");
	x = -1;
	while (++x < 3)
	{
		y = -1;
		while (map[x][++y])
		{
			printf("main: x : %d | y : %d | map[x][y] : [%c]\n",x,y,map[x][y]);
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
*/

// https://sewcode.tistory.com/11

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
	int	g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; //서, 남, 동, 북, 북서, 남서, 남동, 북동
	int	g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};
	int i;

	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == '3')	//공백을 만나 0 return
		return (0);
	map[y][x] = 'x';	//이미 방문한 곳은 x로 체크
	printf("[%d %d], %c\n",y,x,map[y][x]);
	ft_print_dfs_CurrentSituation(map); // 지워야함
	/* 0을 만나 함수를 재귀 호출 */
	i = -1;
	while (++i < 8)
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
char	**init_map(char **map, t_a *a)
{
	int		x;
	int		y;
	char	**test_map;

	/* 테두리 공간을 확보하기 위해 가로,세로가 2씩 큰 맵 생성 */
	a->x_num = get_x(map);
	if (!(test_map = (char **)malloc(sizeof(char *) * (a->x_num + 1))))
		return (0);
	test_map[a->x_num] = 0;	//null
	y = -1;
	int y_num = get_y(map);
	while (++y < a->x_num)
	{
		if (!(test_map[y] = (char *)malloc(sizeof(char) * (y_num + 1))))
			return (0);
		test_map[y][y_num] = 0;	//null
		x = -1;
		while (++x < y_num)
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

/* char **를 free하는 함수 */
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
	char	**test_map;
	t_a		a;

	/* 예시 문제 */
	if (!(map = (char **)malloc(sizeof(char *) * 6)))
		return (0);
	map[0] = " 111";
	map[1] = "1101111111111111";
	map[2] = "10N0000000000001";
	map[3] = "1100111111111111";
	map[4] = " 1111";
	map[5] = 0;







	/* 테스트 시작 */
	test_map = init_map(map, &a);
	free(map);
	is_zero = 0;
	y = -1;
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
		{
			if (test_map[y][x] == '0')	//'0'을 만나면 검사 시작
			{
				is_zero = 1;
				if (check_map(test_map, x, y) == 0)
				{
					printf("ERROR\n");
					free_map(test_map, a.x_num);
					return (0) ;
				}
			}
		}
	}
	if (is_zero == 0)
		printf("ERROR\n");
	else
		printf("OK\n");
	free_map(test_map, a.x_num);
	return (0);
}
