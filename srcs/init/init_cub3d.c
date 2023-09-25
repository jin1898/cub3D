/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/25 18:23:00 by jeekpark         ###   ########.fr       */
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

static void	_init_title_menu_hook(t_game *game)
{
	game->mouse_cursor = set_pixel(0, 0);
	mlx_mouse_hide();
	mlx_hook(game->win, X_EVENT_DESTROY, 0, exit_game, game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, title_menu_key_press, game);
	mlx_hook(game->win, X_EVENT_MOTION_NOTIFY, 0, title_menu_mouse_move, game);
	mlx_hook(game->win, X_EVENT_MOUSE_PRESS, 0, title_menu_mouse_press, game);
	mlx_loop_hook(game->mlx, title_menu_loop_hook, game);
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
	_init_title_menu_hook(game);
	reset_terminal_interface(game);
	return (SUCCESS);
}
