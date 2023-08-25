/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:02:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/25 21:20:12 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_arguments(char **str, int total)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == total)
		return(0);
	return(1);
}

static	int	check_arguments(char **str)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (str[i1])
	{
		while (str[i1][i2])
		{
			if (!(str[i1][i2] >= '0' && str[i1][i2] <= '9'))
				return (0);
			i2++;
		}
		i1++;
		i2 = 0;
	}
	return (1);
}

int	line_validation_rgb(t_game *game)
{
	char	**split;
	char	**split_rgb;

	if ((ft_strncmp(game->str, "F ", 2) == 0 && game->check_parse.floor == 1)
		|| (ft_strncmp(game->str, "C ", 2) == 0 && game->check_parse.ceiling == 1))
		return (FAILURE);
	split = ft_split(game->str, ' ');
	if (split == NULL)
		return (FAILURE);
	if (count_arguments(split, 2)) //(바닥,천장 스페이스기준/ 스플릿1번째)인자값이 2개가 아니라면 작동
	{
		free_split(split);
		return (FAILURE);
	}
	split_rgb = ft_split(split[1], ',');
	free_split(split);
	if (split_rgb == NULL)
		return (FAILURE);
	if (count_arguments(split_rgb, 3)) //(바닥,천장 콤마기준/ 스플릿2번째)인자값이 3개가 아니라면 작동
	{
		free_split(split_rgb);
		return (FAILURE);
	}
	if (ft_strncmp(game->str, "F ", 2) == 0)
	{
		if (!check_arguments(split_rgb))
		{
			free_split(split_rgb);
			return (FAILURE);
		}
		game->floor_color = rgb8_to_int(
				ft_atoi(split_rgb[0]),
				ft_atoi(split_rgb[1]),
				ft_atoi(split_rgb[2])
		);
		(game->check_parse.floor)++;
	}
	else if (ft_strncmp(game->str, "C ", 2) == 0)
	{
		if (!check_arguments(split_rgb))
		{
			free_split(split_rgb);
			return (FAILURE);
		}
		game->ceiling_color = rgb8_to_int(
				ft_atoi(split_rgb[0]),
				ft_atoi(split_rgb[1]),
				ft_atoi(split_rgb[2])
		);
		(game->check_parse.ceiling)++;
	}
	free_split(split_rgb);
	return (SUCCESS);
}

