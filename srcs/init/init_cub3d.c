/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/26 15:11:10 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if ((!ft_strncmp(&str[i + 1], "cub", 3)) && str[i + 4] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
	//문제발생 파일명을 어디까지 허용할것인가? [ 파일명.cub / 파일명.cub.cub / .cub ]이런것들을 허용해도되는것인가?
}

int	init_cub3d(t_game *game, int argc, char **argv)
{
	if (argc != 2 || check_name(argv[1]))
		return (FAILURE);
	ft_memset(game, 0, sizeof(*game));
	game->argv = argv;
	if (init_cub3d_parse(game) == FAILURE)
		return (FAILURE);
	if (map_validation(game) == FAILURE)
		return (FAILURE); //여기에 dfs bfs 검사하는부분
	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (load_images(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
