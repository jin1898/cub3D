/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:41:59 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/06 14:42:22 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	move_vector(t_vector pos, t_vector dir, double distance)
{
	t_vector	res;

	res.x = pos.x + distance * dir.x;
	res.y = pos.y + distance * dir.y;
	return (res);
}
