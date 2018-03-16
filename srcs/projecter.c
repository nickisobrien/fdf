/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projecter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:27:20 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 16:42:41 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_scale(t_world *world)
{
	t_point	*h;
	int		max;

	h = world->point_lst;
	max = (world->rows > world->cols) ? world->rows : world->cols;
	while (h)
	{
		h->x *= (800 / max);
		h->y *= (800 / max);
		h->z *= 28;
		h = h->next;
	}
}

void	adjust_roto(t_world *world)
{
	mult_matrix(world, world->matx);
	mult_matrix(world, world->maty);
	mult_matrix(world, world->matz);
	world->rx = 0;
	world->ry = 0;
	world->rz = 0;
}

void	project(t_world *world)
{
	t_point *h;

	h = world->point_lst;
	while (h)
	{
		if (!(h->z))
			h->z = 1;
		h->x = ((100 * (h->x - world->wwidth / 2)) /
			(100 + h->z)) + world->wwidth / 2;
		h->y = ((100 * (h->y - world->wheight / 2)) /
			(100 + h->z)) + world->wheight / 2;
		h = h->next;
	}
}

void	move(t_world *world, int xadj, int yadj)
{
	t_point *h;

	h = world->point_lst;
	while (h)
	{
		h->x += xadj;
		h->y += yadj;
		h = h->next;
	}
}

void	center(t_world *world)
{
	t_point	*h;
	int		xlow;
	int		xhigh;
	int		ylow;
	int		yhigh;

	h = world->point_lst;
	xlow = h->x;
	xhigh = h->x;
	ylow = h->y;
	yhigh = h->y;
	while (h)
	{
		if (h->x > xhigh)
			xhigh = h->x;
		if (h->x < xlow)
			xlow = h->x;
		if (h->y > yhigh)
			yhigh = h->y;
		if (h->y < ylow)
			ylow = h->y;
		h = h->next;
	}
	move(world, (world->wwidth / 2) - ((xlow + xhigh) / 2),
		(world->wheight / 2) - ((ylow + yhigh) / 2));
}
