/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:16 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/11 17:20:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_vector	_init_belong(t_vector pos)
{
	return (set_vector(round(pos.x), round(pos.y)));
}

static int	_is_wall_collision(t_vector photon, char **map)
{
	if (photon.x - floor(photon.x) == 0.5)
	{
		if (map[(int)round(photon.y)][(int)floor(photon.x)] == '1'
			|| map[(int)round(photon.y)][(int)floor(photon.x) + 1] == '1')
			return (TRUE);
	}
	if (photon.y - floor(photon.y) == 0.5)
	{
		if (map[(int)round(photon.y)][(int)floor(photon.x)] == '1'
			|| map[(int)round(photon.y) + 1][(int)floor(photon.x)] == '1')
			return (TRUE);
	}
	return (FALSE);
}

static void	_move_photon(t_vector *photon, t_vector *belong, t_vector dir)
{
	t_vector	move;

	if (dir.x > 0)
		move.x = (round(photon->x) + 0.5) - photon->x;
	else if (dir.x < 0)
		move.x = (round(photon->x) - 0.5) - photon->x;
	move.y = dir.y / fabs(dir.x) * fabs(move.x);
	if (photon->y + move.y > belong->y + 0.5 || photon->y + move.y < belong->y - 0.5)
	{
		if (dir.y > 0)
			move.y = (round(photon->y) + 0.5) - photon->y;
		else if (dir.y < 0)
			move.y = (round(photon->y) - 0.5) - photon->y;
		move.x = dir.x / fabs(dir.y) * fabs(move.y);
	}
	photon->x = photon->x + move.x;
	photon->y = photon->y + move.y;
	if (photon->x - belong->x == 0.5)
		(belong->x)++;
	else if (photon->x - belong->x == -0.5)
		(belong->x)--;
	else if (photon->y - belong->y == 0.5)
		(belong->y)++;
	else if (photon->y - belong->y == -0.5)
		(belong->y)--;
}

double	ray_casting(char **map, t_vector pos, t_vector dir, double degree)
{
	int			is_hit;
	t_vector	photon;
	t_vector	belong;
	double		res;

	is_hit = FALSE;
	photon = pos;
	belong = _init_belong(pos);
	while (is_hit == FALSE)
	{
		if (_is_wall_collision(photon, map) == TRUE)
			is_hit == TRUE;
		if (is_hit == FALSE)
			_move_photon(&photon, &belong, dir);
	}
	res = _correct_distance(distance_vector(pos, photon), degree);
	return (res);
}
