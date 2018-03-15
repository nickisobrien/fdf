/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:46:55 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/14 18:40:08 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	new_img(t_world *world)
{
	void *img;

	img = mlx_new_image(world->mlx, world->wwidth, world->wheight);
	mlx_put_image_to_window(world->mlx, world->window, img, 0, 0);
}