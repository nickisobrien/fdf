/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:37:06 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 11:21:40 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham_x(t_world *world, int x1, int y1, int x2, int y2, int colored)
{
	int m_new;
	int slope_error_new;
	int x;
	int y;
	int neg;

	neg = 0;
	m_new = 2 * (y2 - y1);
	slope_error_new = m_new - (x2 - x1);
	if (y1 > y2)
	{
		m_new = 2 * -(y1 - y2);
		neg = 1;
	}
	x = x1;
	y = y1;
	while (x <= x2)
	{
		//printf("(%d, %d)\n", x, y);
		if (colored)
			mlx_pixel_put(world->mlx, world->window, x, y, 0xffffff);
		else
			mlx_pixel_put(world->mlx, world->window, x, y, 0x2eff05);
		slope_error_new += m_new;
		if (slope_error_new >= 0 && !neg)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
		else if (slope_error_new <= 0 && neg)
		{
			y--;
			slope_error_new += 2 * (x2 - x1);
		}
		x++;
	}
}

void	bresenham_y(t_world *world, int x1, int y1, int x2, int y2, int colored)
{
	int m_new;
	int slope_error_new;
	int x;
	int y;
	int neg;

	neg = 0;
	m_new = 2 * (x2 - x1);
	slope_error_new = m_new - (y2 - y1);
	if (x1 > x2)
	{
		m_new = 2 * -(x1 - x2);
		neg = 1;
	}
	x = x1;
	y = y1;
	while (y <= y2)
	{
		//printf("(%d, %d)\n", x, y);
		if (colored)
			mlx_pixel_put(world->mlx, world->window, x, y, 0xffffff);
		else
			mlx_pixel_put(world->mlx, world->window, x, y, 0x2eff05);
		slope_error_new += m_new;
		if (slope_error_new >= 0 && !neg)
		{
			x++;
			slope_error_new -= 2 * (y2 - y1);
		}
		else if (slope_error_new <= 0 && neg)
		{
			x--;
			slope_error_new += 2 * (y2 - y1);
		}
		y++;
	}
}

void	bresenham_xfilter(t_world *world, t_point a, t_point b)
{
	if (fabsf(b.x - a.x) < fabsf(b.y - a.y))
	{
		if (b.y < a.y)
			bresenham_yfilter(world, b, a);
		else
			bresenham_yfilter(world, a, b);
		return ;
	}
	if (b.x < a.x)
		bresenham_xfilter(world, b, a);
	else
		bresenham_x(world, a.x, a.y, b.x, b.y, (a.colored || b.colored));
}

void	bresenham_yfilter(t_world *world, t_point a, t_point b)
{
	if (fabsf(b.y - a.y) < fabsf(b.x - a.x))
	{
		if (b.x < a.x)
			bresenham_xfilter(world, b, a);
		else
			bresenham_xfilter(world, a, b);
		return ;
	}
	if (b.y < a.y)
		bresenham_yfilter(world, b, a);
	else
		bresenham_y(world, a.x, a.y, b.x, b.y, (a.colored || b.colored));
}

void	draw(t_world *world)
{
	int i;
	int j;

	j = 0;
	while (j < world->rows)
	{
		i = 0;
		while (i < world->cols)
		{
			//draw across
			if (i + 1 < world->cols)
				bresenham_xfilter(world, world->arr[j][i], world->arr[j][i + 1]);
			//draw down
			if (j + 1 < world->rows)
				bresenham_yfilter(world, world->arr[j][i], world->arr[j + 1][i]);
			i++;
		}
		j++;
	}
}