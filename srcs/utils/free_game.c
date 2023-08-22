/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:27:16 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/22 20:49:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_game(t_game *game)
{
	free(game->north_path);
	free(game->south_path);
	free(game->west_path);
	free(game->east_path);
	free_split(game->map);
}
