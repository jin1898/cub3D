/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:10:27 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/19 14:46:03 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_split(char	**to_free)
{
	size_t	index;

	index = 0;
	if (to_free == NULL)
		return ;
	while (to_free[index])
	{
		free(to_free[index]);
		index++;
	}
	free(to_free);
	return ;
}
