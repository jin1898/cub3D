/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:16 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/16 02:06:33 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_move_ray(t_ray *ray)
{
	if (ray->side.x < ray->side.y)
	{
		ray->side.x += ray->delta.x;
		ray->belong.x += ray->step.x;
		ray->last_move = 'x';
	}
	else
	{
		ray->side.y += ray->delta.y;
		ray->belong.y += ray->step.y;
		ray->last_move = 'y';
	}
}

double	ray_casting(t_game *game, t_ray *ray, t_vector pos, t_vector dir)
{
	init_ray_casting(ray, pos, dir);
	while (TRUE)
	{
		_move_ray(ray);
		if (game->map[(int)ray->belong.y][(int)ray->belong.x] == '1')
			break ;
	}
	if (ray->last_move == 'x')
	{
		ray->hit_point = pos.y + (ray->side.x - ray->delta.x) * dir.y;
		ray->hit_point -= floor(ray->hit_point);
		return (ray->side.x - ray->delta.x);
	}
	else if (ray->last_move == 'y')
	{
		ray->hit_point = pos.x + (ray->side.y - ray->delta.y) * dir.x;
		ray->hit_point -= floor(ray->hit_point);
		return (ray->side.y - ray->delta.y);
	}
	else
		return (0);
}
