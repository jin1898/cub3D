/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:57:55 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/22 07:08:41 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	_add_split(char *to_add, t_game *game, size_t *line_count)
{
	char	**temp;
	size_t	i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * ((*line_count) + 1));
	if (temp == NULL)
		return (FAILURE);
	while (game->map[i])
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = ft_strdup(to_add);
	if (temp[i] == NULL)
	{
		free(temp);
		return (FAILURE);
	}
	temp[i + 1] = NULL;
	free(game->map);
	game->map = temp;
	return (SUCCESS);
}

static int	_check_line(char *str)
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

static int	_start_section(char *str, t_game *game)
{
	if (_check_line(str) == FAILURE)
		return (FAILURE);
	game->map = (char **)malloc(sizeof(char *) * 2);
	if (game->map == NULL)
		return (FAILURE);
	game->map[0] = ft_strdup(str);
	if (game->map[0] == NULL)
		return (FAILURE);
	game->map[1] = NULL;
	return (SUCCESS);
}

int	line_validation_map(t_game *game)
{
	(game->check_parse.map)++;
	if (game->check_parse.map == 1)
	{
		game->check_parse.diff = game->line_count - game->check_parse.map;
		if (_start_section(game->str, game) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (game->check_parse.diff != game->line_count - game->check_parse.map)
			return (FAILURE);
		if (_add_split(game->str, game, &(game->line_count)) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
