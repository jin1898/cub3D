/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_menu_key_press.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:41:49 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/21 14:51:40 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	title_menu_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}
