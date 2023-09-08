/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:45:18 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/08 23:28:34 by sunwoo-jin       ###   ########.fr       */
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

static int	_put_image(char *img, char **split, size_t check_img)
{
	if (!split[1] || img != NULL)
	{
		free_split(split);
		return (FAILURE);
	}
	img = ft_strdup(split[1]); //실패했을시 여기서 릭발생
	if (img == NULL)
	{
		free_split(split);
		return (FAILURE);
	}
	(check_img)++;
	return (SUCCESS);
}

static int	save_after_image_validation(char **split, t_game *game)
{
	if (ft_strncmp(game->str, "NO ", 3) == 0)
	{
		if (_put_image(game->north_path, split,
				game->check_parse.north) == FAILURE)
			return (FAILURE);
	}
	else if (ft_strncmp(game->str, "SO ", 3) == 0)
	{
		if (_put_image(game->south_path, split,
				game->check_parse.south) == FAILURE)
			return (FAILURE);
	}
	else if (ft_strncmp(game->str, "WE ", 3) == 0)
	{
		if (_put_image(game->west_path, split,
				game->check_parse.west) == FAILURE)
			return (FAILURE);
	}
	else if (ft_strncmp(game->str, "EA ", 3) == 0)
	{
		if (_put_image(game->east_path, split,
				game->check_parse.east) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	line_validation_texture(t_game *game)
{
	char	**split;

	split = ft_split(game->str, ' ');
	if (split == NULL)
		return (FAILURE);
	if (_count_arguments(split, 2) == FAILURE)
	{
		free_split(split);
		return (FAILURE);
	}
	if (save_after_image_validation(split, game) == FAILURE)
		return (FAILURE);
	free_split(split);
	return (SUCCESS);
}

// int	line_validation_texture(t_game *game)
// {
// 	char	**split;

// 	split = ft_split(game->str, ' ');
// 	if (split == NULL)
// 		return (FAILURE);
// 	if (_count_arguments(split, 2) == FAILURE) //인자값이 2개가 아니라면 작동
// 	{
// 		free_split(split);
// 		return (FAILURE);
// 	}
// 	if (ft_strncmp(game->str, "NO ", 3) == 0)
// 	{
// 		if(!split[1] || game->north_path != NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		game->north_path = ft_strdup(split[1]);
// 		if (game->north_path == NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		(game->check_parse.north)++;
// 	}
// 	else if (ft_strncmp(game->str, "SO ", 3) == 0)
// 	{
// 		if(!split[1] || game->south_path != NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		game->south_path = ft_strdup(split[1]);
// 		if (game->south_path == NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		(game->check_parse.south)++;
// 	}
// 	else if (ft_strncmp(game->str, "WE ", 3) == 0)
// 	{
// 		if(!split[1] || game->west_path != NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		game->west_path = ft_strdup(split[1]);
// 		if (game->west_path == NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		(game->check_parse.west)++;
// 	}
// 	else if (ft_strncmp(game->str, "EA ", 3) == 0)
// 	{
// 		if(!split[1] || game->east_path != NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		game->east_path = ft_strdup(split[1]);
// 		if (game->east_path == NULL)
// 		{
// 			free_split(split);
// 			return (FAILURE);
// 		}
// 		(game->check_parse.east)++;
// 	}
// 	free_split(split);
// 	return (SUCCESS);
// }