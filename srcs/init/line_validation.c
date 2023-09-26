/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:21:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/26 18:14:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_check_map_slice(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '1' || str[i] == '0'
			|| str[i] == 'N' || str[i] == 'S' || str[i] == 'W'
			|| str[i] == 'E')
			i++;
		else
			return (FAILURE);
	}
	if (i == 0)
		return (FAILURE);
	return (SUCCESS);
}

static int	_4way_image_check(t_game *game)
{
	if (game->check_parse.map != 0
		|| line_validation_texture(game) == FAILURE)
		return (FAILURE);
	return (0);
}

int	line_validation(t_game *game)
{
	(game->line_count)++;
	if (ft_strncmp(game->str, "", 1) == 0)
		;
	else if (ft_strncmp(game->str, "NO ", 3) == 0
		|| ft_strncmp(game->str, "SO ", 3) == 0
		|| ft_strncmp(game->str, "WE ", 3) == 0
		|| ft_strncmp(game->str, "EA ", 3) == 0)
	{
		if (_4way_image_check(game) == FAILURE)
			return (FAILURE);
	}
	else if (ft_strncmp(game->str, "F ", 2) == 0
		|| ft_strncmp(game->str, "C ", 2) == 0)
	{
		if (game->check_parse.map != 0 || line_validation_rgb(game) == FAILURE)
			return (FAILURE);
	}
	else if (_check_map_slice(game->str) == SUCCESS)
	{
		if (line_validation_map(game) == FAILURE)
			return (FAILURE);
	}
	else
		return (FAILURE);
	return (SUCCESS);
}
