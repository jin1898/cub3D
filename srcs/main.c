/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/09 17:24:22 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	aaa(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(aaa);
	if (init_cub3d(&game, argc, argv) == FAILURE)
	{
		printf("Error\nInit failed\n");
		exit_game(&game);
		return (EXIT_FAILURE);
	}

	mlx_mouse_move(game.win, WIN_W / 2, WIN_H / 2);
	game.hook.prev_mouse_x = WIN_W / 2;
	mlx_mouse_hide();
	mlx_hook(game.win, X_EVENT_MOTION_NOTIFY, 0, mouse_move, &game);
	mlx_hook(game.win, X_EVENT_DESTROY, 0, exit_game, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, key_release, &game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}


/* 파씽 검사 받아봄
1.2000을 넣는순간 릭발생
2. 좌표사이에 띄어쓰가있어도 돌아가야한다?
3. 맵이 섬으로 옆에 아래 있어도 되야한다?(단 줄기준으로 띄어있음  안됨)
4. 맵이외의 요소들이 멘데토리 기준 그대로 나오지 않으면 안된다?
*/
