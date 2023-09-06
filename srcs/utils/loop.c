/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:21:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/05 20:39:07 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_reset_core_vector(t_game *game)
{// 위치를 변경해주는 함수 

	//플레이어 위치 바꾸기 
	if (game->hook.state_key_w == TRUE && game->map[(int)(game->player.y - 0.05)][(int)game->player.x] != '1')
		game->player = add_vector(game->player, set_vector(0, -0.05));
	if (game->hook.state_key_s == TRUE && game->map[(int)(game->player.y + 0.05)][(int)game->player.x] != '1')
		game->player = add_vector(game->player, set_vector(0, 0.05));
	if (game->hook.state_key_a == TRUE && game->map[(int)game->player.y][(int)(game->player.x - 0.05)] != '1')
		game->player = add_vector(game->player, set_vector(-0.05, 0));
	if (game->hook.state_key_d == TRUE && game->map[(int)game->player.y][(int)(game->player.x + 0.05)] != '1')
		game->player = add_vector(game->player, set_vector(0.05, 0));

	//플레인 바꾸기 
	if (game->hook.state_key_right == TRUE)
	{
		game->view_angle = rotate_vector(game->view_angle, UNIT_DEGREE);
		game->plane_angle = rotate_vector(game->view_angle, 90);
	}
	if (game->hook.state_key_left == TRUE)
	{
		game->view_angle = rotate_vector(game->view_angle, -UNIT_DEGREE);
		game->plane_angle = rotate_vector(game->view_angle, 90);
	}
	
}

int	loop(t_game *game)
{
	_reset_core_vector(game);
	//render_game_scene(game);
	render_mini_map(game);
	return (0);
}