/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:16 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/13 10:21:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	_init_step(t_vector dir, t_pixel *step)
{
	if (dir.x < 0)
		step->x = -1;
	else
		step->x = 1;
	if (dir.y < 0)
		step->y = -1;
	else
		step->y = 1;
}

static void	_init_delta(t_vector dir, t_vector *delta)
{
	delta->x = fabs(1 / dir.x);
	delta->y = fabs(1 / dir.y);
}

double	ray_casting(t_game *game, t_vector pos, t_vector dir, double degree)
{
	t_vector	belong;
	t_vector	side = {0, 0};
	t_vector	delta;
	t_pixel		step;

	belong.x = (int)pos.x;
	belong.y = (int)pos.y;
	_init_step(dir, &step);
	_init_delta(dir, &delta);
	
	if (dir.x < 0)
		side.x = (pos.x - belong.x) * delta.x;
	else
		side.x = (belong.x + 1.0 - pos.x) * delta.x;
	if (dir.y < 0)
		side.y = (pos.y - belong.y) * delta.y;
	else
		side.y = (belong.y + 1.0 - pos.y) * delta.y;
	
	int flag;
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
		if (game->map[(int)belong.y][(int)belong.x] == '1')
			break;
	}
	
	if (flag = 1)
		return (side.x - delta.x);
	else
		return (side.y - delta.y);
}
