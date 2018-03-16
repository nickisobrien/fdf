/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:52:31 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 17:55:55 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		init_cam(t_world *world)
{
	world->rx = 0.0;
	world->ry = 0.0;
	world->rz = 0.0;
}

void		update_array(t_world *world)
{
	t_point *h;
	int		i;
	int		j;

	h = world->point_lst;
	i = 0;
	while (i < world->rows)
	{
		j = 0;
		while (j < world->cols)
		{
			world->arr[i][j] = *h;
			j++;
			h = h->next;
		}
		i++;
	}
}

void		init_array(t_world *world)
{
	t_point **arr;
	t_point *h;
	int		i;
	int		j;

	h = world->point_lst;
	if (!(arr = malloc(sizeof(t_point *) * world->rows + 1)))
		ft_close();
	i = 0;
	while (i < world->rows)
	{
		if (!(arr[i] = malloc(sizeof(t_point) * world->cols + 1)))
			ft_close();
		j = 0;
		while (j < world->cols)
		{
			arr[i][j] = *h;
			j++;
			h = h->next;
		}
		i++;
	}
	world->arr = arr;
}

t_point		*init_point(int x, int y, int z, int color)
{
	t_point *point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	point->next = NULL;
	point->color = color;
	if (z > 0)
		point->colored = 1;
	else
		point->colored = 0;
	return (point);
}
