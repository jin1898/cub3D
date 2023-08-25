/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/25 21:53:21 by sunwoo-jin       ###   ########.fr       */
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

	background_fill(&game, rgb8_to_int(200, 100, 100));
	rect(&game, set_pixel(10, 10), set_pixel(90, 90), rgb8_to_int(220, 0, 60));
	rect(&game, set_pixel(100, 10), set_pixel(180, 90), rgb8_to_int(0, 40, 210));
	line(&game, set_pixel(190, 10), set_pixel(270, 90), rgb8_to_int(220, 0, 60));
	mlx_put_image_to_window(game.mlx, game.win, game.art.west, 360, 10);

	mlx_hook(game.win, X_EVENT_DESTROY, 0, exit_game, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}

/*
2023/8/25 -start-
1. atoi 0~9까지만 변형가능하게 바꿈
2. 인자값 처리 완료
	2-1. NO ./textures/Blue_Nebula_03-1024x1024.xpm 가 아닌 NO만들어왔을때 처리함
	2-2. F 20,20,20   / C 165,229,255 의 인자 갯수 확인 하는거 완료 
	2-3. NO ./textures/Blue_Nebula_03-1024x1024.xpm 가 아닌 NO ./textures/Blue_Nebula_03-1024x1024.xpm 1 가 들어왔을때 에러처리함
	2-4. NO SO WE EA F C 하나라도 없을떄 처리함 
	2-5. NO SO WE EA가 중복이 있을때 에러처리함(F,C중복처리는 되어있었음.)
2023/8/25 -end-
*/