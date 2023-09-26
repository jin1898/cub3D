/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/26 18:31:03 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	aa(void)
{
	system("sudo leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_game	game;
	atexit(aa);
	if (init_cub3d(&game, argc, argv) == FAILURE)
	{
		printf("Error\nInit failed\n");
		exit_game(&game);
		return (EXIT_FAILURE);
	}
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
