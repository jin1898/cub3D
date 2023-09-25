/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_terminal_interface.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:06:38 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/25 18:28:04 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	_print_map_name(t_game *game)
{
	size_t	name_length;
	size_t	i;
	char	*start_pointer;

	start_pointer = ft_strrchr(game->argv[1], '/');
	if (start_pointer == NULL)
		start_pointer = game->argv[1];
	name_length = ft_strlen(start_pointer);
	name_length -= 4;
	i = 0;
	if (name_length < 47)
	{
		while (i < ((47 - name_length) / 2) - 1)
		{
			printf(" ");
			i++;
		}
		printf("%s", start_pointer + 1);
	}
	else
	{
		i++;
		while (i < 47)
		{
			ft_putchar_fd(start_pointer[i], STDOUT_FILENO);
			i++;
		}
		printf("~");
	}
}

void	reset_terminal_interface(t_game *game)
{
	int	i;

	i = 0;
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