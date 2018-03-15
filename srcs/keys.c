/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:49:15 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/14 18:40:09 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


int			key_pressed_hook(int key, t_world *world)
{
	if (key == 124)
		world->ry = 0.04;
	if (key == 123)
		world->ry = -0.04;
	if (key == 126)
		world->rx = 0.04;
	if (key == 125)
		world->rx = -0.04;
	render(world);
	return (0);
}