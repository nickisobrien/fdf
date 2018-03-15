/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:35:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 16:03:31 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		render(t_world *world)
{
	new_img(world);
	set_mat(world);
	adjust_roto(world);
	center(world);
	init_array(world);
	draw(world);
}

int			main(int argc, char **argv)
{
	t_world world;

	world.wwidth = 1250;
	world.wheight = 900;
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf file");
		return (-1);
	}
	world.file = argv[1];
	if ((world.fd = open(world.file, O_RDONLY)) == -1)
		ft_error(&world);
	read_file(&world);
	close(world.fd);
	world.mlx = mlx_init();
	world.window = mlx_new_window(world.mlx,
		world.wwidth, world.wheight, world.file);
	set_scale(&world);
	init_cam(&world);
	mlx_hook(world.window, 2, 0, key_pressed_hook, &world);
	render(&world);
	mlx_loop(world.mlx);
	return (0);
}
