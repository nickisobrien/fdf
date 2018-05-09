/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:46:55 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 23:06:32 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_image(t_world *w)
{
	w->img = mlx_new_image(w->mlx, w->wwidth, w->wheight);
	w->ptr = mlx_get_data_addr(w->img,
		&w->bpp, &w->size_line, &w->endian);
	w->bpp /= 8;
}

void	img_pixel_put(t_world *w, int x, int y, int color)
{
	if (x >= 0 && x < w->wwidth && y >= 0 && y < w->wheight)
		*(int *)(w->ptr + (int)((y * w->wwidth + x) * w->bpp)) = color;
}

void	clear_image(t_world *w)
{
	ft_bzero(w->ptr, w->wwidth * w->wheight * w->bpp);
}
