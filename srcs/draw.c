/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:37:06 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 22:56:15 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham_x(t_world *world, t_point a, t_point b)
{
	int m_new;
	int slope_error_new;
	int x;
	int y;
	int neg;

	neg = 0;
	m_new = 2 * (b.y - a.y);
	slope_error_new = m_new - (b.x - a.x);
	if (a.y > b.y && (neg = 1))
		m_new = 2 * -(a.y - b.y);
	x = a.x;
	y = a.y;
	while (x <= b.x)
	{
		if (a.colored || b.colored)
			img_pixel_put(world, x, y, 0xffffff);
		else
			img_pixel_put(world, x, y, 0x2eff05);
		slope_error_new += m_new + (x++ * 0);
		if (slope_error_new >= 0 && !neg)
			slope_error_new -= 2 * (b.x - a.x) + (y++ * 0);
		else if (slope_error_new <= 0 && neg)
			slope_error_new += 2 * (b.x - a.x) + (y-- * 0);
	}
}

void	bresenham_y(t_world *world, t_point a, t_point b)
{
	int m_new;
	int slope_error_new;
	int x;
	int y;
	int neg;

	neg = 0;
	m_new = 2 * (b.x - a.x);
	slope_error_new = m_new - (b.y - a.y);
	if (a.x > b.x && (neg = 1))
		m_new = 2 * -(a.x - b.x);
	x = a.x;
	y = a.y;
	while (y <= b.y)
	{
		if (a.colored || b.colored)
			img_pixel_put(world, x, y, 0xffffff);
		else
			img_pixel_put(world, x, y, 0x2eff05);
		slope_error_new += m_new + (y++ * 0);
		if (slope_error_new >= 0 && !neg)
			slope_error_new -= 2 * (b.y - a.y) + (x++ * 0);
		else if (slope_error_new <= 0 && neg)
			slope_error_new += 2 * (b.y - a.y) + (x-- * 0);
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
		bresenham_x(world, a, b);
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
		bresenham_y(world, a, b);
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
			if (i + 1 < world->cols)
				bresenham_xfilter(world, world->arr[j][i],
					world->arr[j][i + 1]);
			if (j + 1 < world->rows)
				bresenham_yfilter(world, world->arr[j][i],
					world->arr[j + 1][i]);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(world->mlx, world->window, world->img, 0, 0);
}
