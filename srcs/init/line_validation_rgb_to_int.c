/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_get_rgb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:00:25 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/09/10 17:01:54 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_number_validation(size_t i1, size_t i2, char **str)
{
	if (i2 >= 3)
	{
		free_split(str);
		return (FAILURE);
	}
	if (!(str[i1][i2] >= '0' && str[i1][i2] <= '9'))
	{
		free_split(str);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	_check_arguments(char **str)
{
	size_t	i1;
	size_t	i2;
	int		temp_num;

	i1 = 0;
	i2 = 0;
	while (str[i1])
	{
		temp_num = ft_atoi(str[i1]);
		if (temp_num > 255 || temp_num < 0)
			return (FAILURE);
		while (str[i1][i2])
		{
			if (_number_validation (i1, i2, str) == FAILURE)
				return (FAILURE);
			i2++;
		}
		i1++;
		i2 = 0;
	}
	return (SUCCESS);
}

int	line_validation_get_rgb8(t_game *game, char **rgb)
{
	if (ft_strncmp(game->str, "F ", 2) == 0)
	{
		if (_check_arguments(rgb) == FAILURE)
			return (FAILURE);
		game->floor_color = rgb8_to_int(
				ft_atoi(rgb[0]),
				ft_atoi(rgb[1]),
				ft_atoi(rgb[2]));
		(game->check_parse.floor)++;
	}
	else if (ft_strncmp(game->str, "C ", 2) == 0)
	{
		if (_check_arguments(rgb) == FAILURE)
			return (FAILURE);
		game->ceiling_color = rgb8_to_int(
				ft_atoi(rgb[0]),
				ft_atoi(rgb[1]),
				ft_atoi(rgb[2]));
		(game->check_parse.ceiling)++;
	}
	return (SUCCESS);
}
