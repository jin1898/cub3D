/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/22 21:02:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	aaa(void)
{
	system("leaks cub3D");
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