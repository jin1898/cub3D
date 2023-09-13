/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:16 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/13 19:10:39 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_pixel	_init_step(t_vector dir)
{
	t_pixel	res;

	if (dir.x < 0)
		res.x = -1;
	else
		res.x = 1;
	if (dir.y < 0)
		res.y = -1;
	else
		res.y = 1;
	return (res);
}

static t_vector	_init_delta(t_vector dir)
{
	t_vector	res;

	res.x = fabs(1 / dir.x);
	res.y = fabs(1 / dir.y);
	return (res);
}

static t_vector	_init_belong(t_vector pos)
{
	t_vector	res;

	res.x = (int)pos.x;
	res.y = (int)pos.y;
	return (res);
}

static t_vector	_init_side(t_vector dir, t_vector pos, t_vector belong, t_vector delta)
{
	t_vector	res;

	if (dir.x < 0)
		res.x = (pos.x - (belong.x)) * delta.x;
	else
		res.x = (belong.x + 1.0 - pos.x) * delta.x;
	if (dir.y < 0)
		res.y = (pos.y - (belong.y)) * delta.y;
	else
		res.y = (belong.y + 1.0 - pos.y) * delta.y;
	return (res);
}



double	ray_casting(t_game *game, t_vector pos, t_vector dir, int *face)
{
	t_pixel		step;
	t_vector	delta;
	t_vector	belong;
	t_vector	side;
	int			flag = 10;
	int			count;

	step = _init_step(dir);
	delta = _init_delta(dir);
	belong = _init_belong(pos);
	side = _init_side(dir, pos, belong, delta);
	while (TRUE)
	{
		if (side.x < side.y)
		{
			side.x += delta.x;
			belong.x += step.x;
			flag = 1;
		}
		else
		{
			side.y += delta.y;
			belong.y += step.y;
			flag = 2;
		}
		count++;
		if (count == 50)
			return (0);
		if (game->map[(int)belong.y][(int)belong.x] == '1')
			break;
	}
	if (flag == 1)
	{
		if (step.x == 1)
			*face = 1;
		else if (step.x == -1)
			*face = 2;
		return (side.x - delta.x);
	}
	else if (flag == 2)
	{
		if (step.y == 1)
			*face = 3;
		else if (step.y == -1)
			*face = 4;
		return (side.y - delta.y);
	}
	else
		return (0);
}
