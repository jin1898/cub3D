/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/03 16:52:21 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	aaa(void)
{
	system("leaks -q cub3D");
}

int main(int argc, char **argv)
{
	t_game	game;

	atexit(aaa);
	if (init_cub3d(&game, argc, argv) == FAILURE)
	{
		printf("Error\nInit failed\n");
		exit_game(&game);
		return (EXIT_FAILURE);
	}

	render_mini_map(&game);
	
	mlx_hook(game.win, X_EVENT_DESTROY, 0, exit_game, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}

/*
!!!! 문제가 발생할만한 부분에는  " //문제발생 [설명]" 이라고 적음 !!!!


2023/8/25 -start-
1. atoi 0~9까지만 변형가능하게 바꿈
2. 인자값 처리 완료
	2-1. NO ./textures/Blue_Nebula_03-1024x1024.xpm 가 아닌 NO만들어왔을때 처리함
	2-2. F 20,20,20   / C 165,229,255 의 인자 갯수 확인 하는거 완료
	2-3. NO ./textures/Blue_Nebula_03-1024x1024.xpm 가 아닌 NO ./textures/Blue_Nebula_03-1024x1024.xpm 1 가 들어왔을때 에러처리함
	2-4. NO SO WE EA F C 하나라도 없을떄 처리함
	2-5. NO SO WE EA가 중복이 있을때 에러처리함(F,C중복처리는 되어있었음.)
2023/8/25 -end-

2023/8/26 -start-
1. 맵유효성 검사 만드는중
	1-1. 파일이름 ".cub"형식인지 확인 [파일이름.cub / 파일이름.cub.cub / .cub] 모두 참으로 처리됨 [ 파일이름.cuba / .cuba ] 오류로 처리완료
2023/8/26 -end-
*/
