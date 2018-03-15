/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:12:25 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 11:30:38 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FDF_H
# define __FDF_H

# include "libft.h"
# include "mlx.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# define BUFF_SIZE 50

typedef struct 	s_point
{
	float			x;
	float			y;
	float			z;
	int				colored;
	int				color;
	struct s_point	*next;
}				t_point;

typedef struct 	s_world
{
	int		wwidth;
	int		wheight;
	int		cols;
	int		rows;
	int		fd;
	char 	*file;
	int 	lines;
	char 	**tab;
	void	*mlx;
	void	*window;
	t_point	*point_lst;
	t_point **arr;
	float	matx[4][4];
	float	maty[4][4];
	float	matz[4][4];
	float	rx;
	float	ry;
	float	rz;
}				t_world;

//error.c
void	ft_close(t_world *world);

//matrix.c
void	mult_matrix(t_world *world, float mat[4][4]);
void	identity_matrix(float mat[4][4]);
void	set_mat(t_world *world);

//draw.c
void	bresenham_x(t_world *world, int x1, int y1, int x2, int y2, int colored);
void	bresenham_y(t_world *world, int x1, int y1, int x2, int y2, int colored);
void	bresenham_xfilter(t_world *world, t_point a, t_point b);
void	bresenham_yfilter(t_world *world, t_point a, t_point b);
void	draw(t_world *world);

//keys.c
int		key_pressed_hook(int key, t_world *world);

//init.c
void		init_cam(t_world *world);
void		init_array(t_world *world);
t_point		*init_point(int x, int y, int z, int color);

void	new_img(t_world *world);
void	set_scale(t_world *world);
void	adjust_roto(t_world *world);
void	project(t_world *world);
void	move(t_world *world, int xadj, int yadj);
void	center(t_world *world);
void	graph(t_world *world);
void		render(t_world *world);

void	print_array(t_world *world);
void		get_wh(t_world *world);
void	read_file(t_world *world);

#endif