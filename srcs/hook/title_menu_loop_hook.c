/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_menu_loop_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:30:56 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/25 13:46:16 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	title_menu_loop_hook(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->art.title_menu.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->art.mouse_cursor.img,
		game->mouse_cursor.x, game->mouse_cursor.y);
	return (0);
}
