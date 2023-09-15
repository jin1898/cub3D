/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:22:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/15 23:46:38 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	add_vector(t_vector vector1, t_vector vector2)
{
	t_vector	res;

	res.x = vector1.x + vector2.x;
	res.y = vector1.y + vector2.y;
	return (res);
}
