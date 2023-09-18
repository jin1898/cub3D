/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/18 16:38:33 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_check_name(char *str)
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
}

int	init_cub3d(t_game *game, int argc, char **argv)
{
	ft_memset(game, 0, sizeof(*game));
	if (argc != 2 || _check_name(argv[1]))
		return (FAILURE);
	game->argv = argv;
	if (init_cub3d_parse(game) == FAILURE)
		return (FAILURE);
	if (map_validation(game) == FAILURE)
		return (FAILURE);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (load_images(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
