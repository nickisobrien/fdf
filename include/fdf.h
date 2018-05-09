/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:12:25 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 23:08:23 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				colored;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct		s_world
{
	void			*img;
	void			*ptr;
	int				bpp;
	int				endian;
	int				size_line;
	int				wwidth;
	int				wheight;
	int				cols;
	int				rows;
	int				fd;
	char			*file;
	int				lines;
	char			**tab;
	void			*mlx;
	void			*window;
	t_point			*point_lst;
	t_point			**arr;
	float			matx[4][4];
	float			maty[4][4];
	float			matz[4][4];
	float			rx;
	float			ry;
	float			rz;
}					t_world;

void				ft_close(void);
void				ft_error(void);
void				ft_usage(void);

void				mult_matrix(t_world *world, float mat[4][4]);
void				identity_matrix(float mat[4][4]);
void				set_mat(t_world *world);

void				bresenham_x(t_world *world, t_point a, t_point b);
void				bresenham_y(t_world *world, t_point a, t_point b);
void				bresenham_xfilter(t_world *world, t_point a, t_point b);
void				bresenham_yfilter(t_world *world, t_point a, t_point b);
void				draw(t_world *world);

int					key_pressed_hook(int key, t_world *world);

void				init_cam(t_world *world);
void				init_array(t_world *world);
t_point				*init_point(int x, int y, int z, int color);
void				update_array(t_world *world);

void				init_image(t_world *w);
void				img_pixel_put(t_world *w, int x, int y, int color);
void				clear_image(t_world *w);

void				set_scale(t_world *world);
void				adjust_roto(t_world *world);
void				project(t_world *world);
void				move(t_world *world, int xadj, int yadj);
void				center(t_world *world);

void				render(t_world *world);

void				read_file(t_world *world);
void				read_line(t_world *world, char *s);

#endif
