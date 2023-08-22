/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:55:49 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/11 13:38:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	background_fill(t_game *game, int color)
{
	rect(game, set_pixel(0, 0), set_pixel(WIN_W, WIN_H), color);
	return ;
}
