/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:17:27 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/15 23:46:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_int(int num, int in_max, int out_max)
{
	return (num * out_max / in_max);
}
