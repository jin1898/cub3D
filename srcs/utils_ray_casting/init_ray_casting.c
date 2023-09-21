/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:36:56 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/18 21:43:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_vector	_init_step(t_vector dir)
{
	t_vector	res;

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

static t_vector	_init_side(t_vector dir,
	t_vector pos, t_vector belong, t_vector delta)
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

void	init_ray_casting(t_ray *ray, t_vector pos, t_vector dir)
{
	ray->step = _init_step(dir);
	ray->delta = _init_delta(dir);
	ray->belong = _init_belong(pos);
	ray->side = _init_side(dir, pos, ray->belong, ray->delta);
}
