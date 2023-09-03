/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:48:52 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/03 17:51:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_step(t_pixel first, t_pixel second, t_vector *step)
{
	if (first.x < second.x)
		step->x = 1;
	else
		step->x = -1;
	if (first.y < second.y)
		step->y = 1;
	else
		step->x = -1;
}

static int	init_diff(t_pixel first, t_pixel second, t_vector *diff)
{
	diff->x = ft_abs(second.x - first.x);
	diff->y = -ft_abs(second.y - first.y);
	return (diff->x + diff->y);
}

void	draw_line_to_img(t_component *component, t_pixel first, t_pixel second, int color)
{// DDA 알고리즘사용 브라함슨?을 이용하여 선을 만들었다. 안티엘런싱
	t_vector	step;//벡터 더블로 위치를 받음(부드럽게 나와야지 끊기면 안되니까.
	t_vector	diff;
	int			err;
	int			e2;

	err = init_diff(first, second, &diff);// 미분을 구해서 선이 그려진척하기 (계단식색칠이 되는데 사실 그 지점의 픽셀은 모두 색칠됨.)
	init_step(first, second, &step);
	while (1)//선을 다 찍을때까지 돌린다.
	{
		draw_pixel_to_img(component, first, color); // 한점씩 찍는다.
		if (first.x == second.x && first.y == second.y) // 끝좌표에 도달하면 끝냄
			break ;
		e2 = 2 * err;
		if (e2 >= diff.y)
		{
			err += diff.y;//같은 범위만 돌면 안되니까 이동해주면서 그려줘야해서 더해줌
			first.x += step.x;//미분값구하는 공식에 의해서 x 의 변화량의 비율을 얻은 만큼 더해준다.
		}
		if (e2 <= diff.x)
		{
			err += diff.x;//같은 범위만 돌면 안되니까 이동해주면서 그려줘야해서 더해줌
			first.y += step.y;//미분값구하는 공식에 의해서 y 의 변화량의 비율을 얻은 만큼 더해준다.
		}
	}
}
