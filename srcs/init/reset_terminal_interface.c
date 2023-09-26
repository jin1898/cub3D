/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_terminal_interface.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:06:38 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/26 14:55:03 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_print_map_name_space(size_t size, char *start_pointer)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (start_pointer[0] == '/')
		start_pointer++;
	printf("%s", start_pointer);
}

void	_print_map_name_no_space(char *start_pointer)
{
	size_t	i;

	i = 0;
	if (start_pointer[0] == '/')
		start_pointer++;
	while (i < 46)
	{
		ft_putchar_fd(start_pointer[i], STDOUT_FILENO);
		i++;
	}
	ft_putchar_fd('~', STDOUT_FILENO);
}

void	_print_map_name(t_game *game)
{
	size_t	name_length;
	char	*start_pointer;

	start_pointer = ft_strrchr(game->argv[1], '/');
	if (start_pointer == NULL)
		start_pointer = game->argv[1];
	name_length = ft_strlen(start_pointer);
	if (name_length < 47)
		_print_map_name_space(((47 - name_length) / 2), start_pointer);
	else
		_print_map_name_no_space(start_pointer);
}

void	reset_terminal_interface(t_game *game)
{
	printf("\033[2J\033[H\n\n\033[1;33m");
	printf(" _   _______ _      _      ___________  ______ \n");
	printf("| | / /_   _| |    | |    |  ___| ___ \\ | ___ \\\n");
	printf("| |/ /  | | | |    | |    | |__ | |_/ / | |_/ /\n");
	printf("|    \\  | | | |    | |    |  __||    /  | ___ \\\n");
	printf("| |\\  \\_| |_| |____| |____| |___| |\\ \\  | |_/ /\n");
	printf("\\_| \\_/\\___/\\_____/\\_____/\\____/\\_| \\_| \\____/ \n");
	printf("Mandatory part                    Killer banana\033[1;32m\n\n");
	printf("\n                GAME IS RUNNING                \n\n\n");
	_print_map_name(game);
	printf("\n\n\n");
}
