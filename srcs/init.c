/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:52:31 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 16:37:11 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		init_cam(t_world *world)
{
	world->rx = 0.3;
	world->ry = 0.3;
	world->rz = 0.3;
}

void		init_array(t_world *world)
{
	t_point **arr;
	t_point *h;
	int		i;
	int		j;

	h = world->point_lst;
	if (!(arr = malloc(sizeof(t_point *) * world->rows + 1)))
		ft_close(world);
	i = 0;
	while (i < world->rows)
	{
		if (!(arr[i] = malloc(sizeof(t_point) * world->cols + 1)))
			ft_close(world);
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
