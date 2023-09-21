/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:19:37 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/15 22:20:52 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	map_double(double num, double in_max, double out_max)
{
	return (num * out_max / in_max);
}
