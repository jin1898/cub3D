/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_menu_mouse_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:31:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 14:52:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	title_menu_mouse_move(int x, int y, t_game *game)
{
	game->mouse_cursor.x = x;
	game->mouse_cursor.y = y;
	return (SUCCESS);
}
