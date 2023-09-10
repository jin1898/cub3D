/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:02:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/10 17:33:52 by sunwoo-jin       ###   ########.fr       */
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

static int	_check_do_split_rgb(char **split_rgb, t_game *game)
{
	if (_count_arguments(split_rgb, 3) == FAILURE)
	{
		free_split(split_rgb);
		return (FAILURE);
	}
	if (line_validation_get_rgb8(game, split_rgb) == FAILURE)
	{
		free_split(split_rgb);
		return (FAILURE);
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
	if (_check_do_split_rgb(split_rgb, game) == FAILURE)
		return (FAILURE);
	free_split(split_rgb);
	return (SUCCESS);
}
