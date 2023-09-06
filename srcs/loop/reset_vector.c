/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:09 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/06 17:55:30 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_move_wall_collision(char **map,
	t_game *game, t_vector pos, t_vector dir)
{
	t_vector	target;
	int			x;
	int			y;

	target = move_vector(pos, dir, DISTANCE_UNIT);
	x = (int)round(target.x);
	y = (int)round(target.y);
	if (map[y][x] == '1')
		return (TRUE);
	return (FALSE);
}

void	_single_key(t_game *game, t_hook hook, char **map)
{
	if (hook.state_key_w == TRUE && hook.state_key_a == FALSE
		&& hook.state_key_s == FALSE && hook.state_key_d == FALSE
		&& _move_wall_collision(map, game, game->player,
			game->view_angle) == FALSE)
		game->player = move_vector(game->player,
				game->view_angle, DISTANCE_UNIT);
	else if (hook.state_key_w == FALSE && hook.state_key_a == FALSE
		&& hook.state_key_s == TRUE && hook.state_key_d == FALSE
		&& _move_wall_collision(map, game, game->player,
			rotate_vector(game->view_angle, 180)) == FALSE)
		game->player = move_vector(game->player,
				rotate_vector(game->view_angle, 180), DISTANCE_UNIT);
	else if (hook.state_key_w == FALSE && hook.state_key_a == TRUE
		&& hook.state_key_s == FALSE && hook.state_key_d == FALSE
		&& _move_wall_collision(map, game, game->player,
			rotate_vector(game->view_angle, -90)) == FALSE)
		game->player = move_vector(game->player,
				rotate_vector(game->view_angle, -90), DISTANCE_UNIT);
	else if (hook.state_key_w == FALSE && hook.state_key_a == FALSE
		&& hook.state_key_s == FALSE && hook.state_key_d == TRUE
		&& _move_wall_collision(map, game, game->player,
			rotate_vector(game->view_angle, 90)) == FALSE)
		game->player = move_vector(game->player,
				rotate_vector(game->view_angle, 90), DISTANCE_UNIT);
}

void	_multiple_key(t_game *game, t_hook hook, char **map)
{
	if (hook.state_key_w == TRUE && hook.state_key_a == TRUE
		&& hook.state_key_s == FALSE && hook.state_key_d == FALSE
		&& _move_wall_collision(map, game, game->player,
			rotate_vector(game->view_angle, -45)) == FALSE)
		game->player = move_vector(game->player,
				rotate_vector(game->view_angle, -45), DISTANCE_UNIT);
	else if (hook.state_key_w == TRUE && hook.state_key_a == FALSE
		&& hook.state_key_s == FALSE && hook.state_key_d == TRUE
		&& _move_wall_collision(map, game, game->player,
			rotate_vector(game->view_angle, 45)) == FALSE)
		game->player = move_vector(game->player,
				rotate_vector(game->view_angle, 45), DISTANCE_UNIT);
	else if (hook.state_key_w == FALSE && hook.state_key_a == TRUE
		&& hook.state_key_s == TRUE && hook.state_key_d == FALSE
		&& _move_wall_collision(map, game, game->player,
			rotate_vector(game->view_angle, -135)) == FALSE)
		game->player = move_vector(game->player,
				rotate_vector(game->view_angle, -135), DISTANCE_UNIT);
	else if (hook.state_key_w == FALSE && hook.state_key_a == FALSE
		&& hook.state_key_s == TRUE && hook.state_key_d == TRUE
		&& _move_wall_collision(map, game, game->player,
			rotate_vector(game->view_angle, 135)) == FALSE)
		game->player = move_vector(game->player,
				rotate_vector(game->view_angle, 135), DISTANCE_UNIT);
}

static int	_count_key_press(t_hook hook)
{
	int	res;

	res = 0;
	res += hook.state_key_a;
	res += hook.state_key_d;
	res += hook.state_key_s;
	res += hook.state_key_w;
	return (res);
}

void	reset_vector(t_game *game, t_hook hook, char **map)
{
	if (_count_key_press(hook) == 1)
		_single_key(game, hook, map);
	else
		_multiple_key(game, hook, map);
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
