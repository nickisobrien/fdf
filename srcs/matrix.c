/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:44:06 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 15:29:10 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	identity_matrix(float mat[4][4])
{
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = 0;
	mat[1][0] = 0;
	mat[1][1] = 1;
	mat[1][2] = 0;
	mat[1][3] = 0;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}

void	mult_matrix(t_world *world, float mat[4][4])
{
	float	x;
	float	y;
	float	z;
	t_point *h;

	h = world->point_lst;
	while (h)
	{
		x = h->x;
		y = h->y;
		z = h->z;
		h->x = x * mat[0][0] + y * mat[1][0] + z * mat[2][0] + mat[3][0];
		h->y = x * mat[0][1] + y * mat[1][1] + z * mat[2][1] + mat[3][1];
		h->z = x * mat[0][2] + y * mat[1][2] + z * mat[2][2] + mat[3][2];
		h = h->next;
	}
}

void	set_mat(t_world *world)
{
	identity_matrix(world->matx);
	identity_matrix(world->maty);
	identity_matrix(world->matz);
	world->matx[1][1] = cos(world->rx);
	world->matx[1][2] = sin(world->rx);
	world->matx[2][1] = -sin(world->rx);
	world->matx[2][2] = cos(world->rx);
	world->maty[0][0] = cos(world->ry);
	world->maty[0][2] = -sin(world->ry);
	world->maty[2][0] = sin(world->ry);
	world->maty[2][2] = cos(world->ry);
	world->matz[0][0] = cos(world->rz);
	world->matz[0][1] = sin(world->rz);
	world->matz[1][0] = -sin(world->rz);
	world->matz[1][1] = cos(world->rz);
}
