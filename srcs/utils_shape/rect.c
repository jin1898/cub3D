/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:00:31 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/11 13:37:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rect(t_game *game, t_pixel first, t_pixel second, int color)
{
	int	i;
	int	j;

	if (first.x >= second.x || first.y >= second.y
		|| first.x > WIN_W || second.x > WIN_W
		|| first.y > WIN_H || second.y > WIN_H)
		return ;
	i = first.x;
	while (i < second.x)
	{
		j = first.y;
		while (j < second.y)
		{
			mlx_pixel_put(game->mlx, game->win, i, j, color);
			j++;
		}
		i++;
	}
	return ;
}
