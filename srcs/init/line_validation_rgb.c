/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:02:08 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/22 21:29:07 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (0) //(바닥,천장 스페이스기준/ 스플릿1번째)인자값이 2개가 아니라면 작동
	{
		free_split(split);
		return (FAILURE);
	}
	split_rgb = ft_split(split[1], ',');
	free_split(split);
	if (split_rgb == NULL)
		return (FAILURE);
	if (0) //(바닥,천장 콤마기준/ 스플릿2번째)인자값이 3개가 아니라면 작동
	{
		free_split(split_rgb);
		return (FAILURE);
	}
	if (ft_strncmp(game->str, "F ", 2) == 0)
	{
		game->floor_color = rgb8_to_int(
				ft_atoi(split_rgb[0]),
				ft_atoi(split_rgb[1]),
				ft_atoi(split_rgb[2])
		);
		(game->check_parse.floor)++;
	}
	else if (ft_strncmp(game->str, "C ", 2) == 0)
	{
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
