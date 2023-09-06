/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:45:18 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/06 13:38:03 by jsunwoo          ###   ########.fr       */
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
	return (FAILURE);
}

int	line_validation_texture(t_game *game)
{
	char	**split;

	split = ft_split(game->str, ' ');
	if (split == NULL)
		return (FAILURE);
	if (_count_arguments(split, 2) == FAILURE) //인자값이 2개가 아니라면 작동
	{
		free_split(split);
		return (FAILURE);
	}
	if (ft_strncmp(game->str, "NO ", 3) == 0)
	{
		if(!split[1] || game->north_path != NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		game->north_path = ft_strdup(split[1]);
		if (game->north_path == NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		(game->check_parse.north)++;
	}
	else if (ft_strncmp(game->str, "SO ", 3) == 0)
	{
		if(!split[1] || game->south_path != NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		game->south_path = ft_strdup(split[1]);
		if (game->south_path == NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		(game->check_parse.south)++;
	}
	else if (ft_strncmp(game->str, "WE ", 3) == 0)
	{
		if(!split[1] || game->west_path != NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		game->west_path = ft_strdup(split[1]);
		if (game->west_path == NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		(game->check_parse.west)++;
	}
	else if (ft_strncmp(game->str, "EA ", 3) == 0)
	{
		if(!split[1] || game->east_path != NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		game->east_path = ft_strdup(split[1]);
		if (game->east_path == NULL)
		{
			free_split(split);
			return (FAILURE);
		}
		(game->check_parse.east)++;
	}
	free_split(split);
	return (SUCCESS);
}
