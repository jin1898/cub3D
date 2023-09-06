/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:02:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/06 17:38:34 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_count_arguments(char **str, size_t total)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (i == total)
		return (SUCCESS);
	free_split(str);
	return (FAILURE);
}

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

static int	_get_rgb8(t_game *game, char **rgb)
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

int	line_validation_rgb(t_game *game)
{
	char	**split;
	char	**split_rgb;

	if ((ft_strncmp(game->str, "F ", 2) == 0 && game->check_parse.floor == 1)
		|| (ft_strncmp(game->str, "C ", 2) == 0
			&& game->check_parse.ceiling == 1))
		return (FAILURE);
	split = ft_split(game->str, ' ');
	if (split == NULL)
		return (FAILURE);
	if (_count_arguments(split, 2) == FAILURE)
		return (FAILURE);
	split_rgb = ft_split(split[1], ',');
	free_split(split);
	if (split_rgb == NULL)
		return (FAILURE);
	if (_count_arguments(split_rgb, 3) == FAILURE)
		return (FAILURE);
	if (_get_rgb8(game, split_rgb) == FAILURE)
		return (FAILURE);
	free_split(split_rgb);
	return (SUCCESS);
}

