/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:36:11 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/08/28 20:36:52 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_print_dfs_CurrentSituation(char ** map) // 지워야함
{
	int x = 0;
	int y = 0;

	printf("\n --start---- \n");
	while (map[x])
	{
		printf("[x : %d] : ", x);
		while(map[x][y])
		{
			printf("[%c] ", map[x][y]);
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
	printf("\n --end---- \n");
}
