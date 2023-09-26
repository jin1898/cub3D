/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:02:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/26 21:09:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_count_comma(t_game *game)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (game->str[i])
	{
		if (game->str[i] == ',')
			res++;
		i++;
	}
	return (res);
}

static int	_count_argument(char **split, int count)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i == count)
		return (SUCCESS);
	free_split(split);
	return (FAILURE);
}

static int	_check_front_zero(char **split_rgb)
{
	int	i;

	i = 0;
	while (split_rgb[i])
	{
		if (split_rgb[i][0] == '0')
		{
			free_split(split_rgb);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static char	**_get_split_rgb(char **split)
{
	char	**res;

	if (split == NULL)
		return (NULL);
	if (_count_argument(split, 2) == FAILURE)
		return (NULL);
	res = ft_split(split[1], ',');
	free_split(split);
	if (res == NULL)
		return (NULL);
	if (_count_argument(res, 3) == FAILURE)
		return (NULL);
	if (_check_front_zero(res) == FAILURE)
		return (NULL);
	return (res);
}

int	line_validation_rgb(t_game *game)
{
	char	**split_rgb;

	if ((ft_strncmp(game->str, "F ", 2) == 0 && game->check_parse.floor == 1)
		|| (ft_strncmp(game->str, "C ", 2) == 0
			&& game->check_parse.ceiling == 1)
		|| _count_comma(game) != 2)
		return (FAILURE);
	split_rgb = _get_split_rgb(ft_split(game->str, ' '));
	if (split_rgb == NULL)
		return (FAILURE);
	if (line_validation_get_rgb8(game, split_rgb) == FAILURE)
	{
		free_split(split_rgb);
		return (FAILURE);
	}
	free_split(split_rgb);
	return (SUCCESS);
}
