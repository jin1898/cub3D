/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:48:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/03 14:04:52 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_step(t_pixel first, t_pixel second, t_vector *step)
{
	if (first.x < second.x)
		step->x = 1;
	else
		step->x = -1;
	if (first.y < second.y)
		step->y = 1;
	else
		step->x = -1;
}

static int	init_diff(t_pixel first, t_pixel second, t_vector *diff)
{
	diff->x = ft_abs(second.x - first.x);
	diff->y = -ft_abs(second.y - first.y);
	return (diff->x + diff->y);
}

void	draw_line_to_img(t_component *component,
	t_pixel first, t_pixel second, int color)
{
	t_vector	step;
	t_vector	diff;
	int			err;
	int			e2;

	err = init_diff(first, second, &diff);
	init_step(first, second, &step);
	while (1)
	{
		draw_pixel_to_img(component, first, color);
		if (first.x == second.x && first.y == second.y)
			break ;
		e2 = 2 * err;
		if (e2 >= diff.y)
		{
			err += diff.y;
			first.x += step.x;
		}
		if (e2 <= diff.x)
		{
			err += diff.x;
			first.y += step.y;
		}
	}
}
