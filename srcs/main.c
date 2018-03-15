/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:35:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 11:27:33 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Now here is what the transformation matrices look like, written in C:

float mat1[4][4], mat2[4][4];

void MAT_Identity(float mat[4][4])
{
    mat[0][0]=1; mat[0][1]=0; mat[0][2]=0; mat[0][3]=0;
    mat[1][0]=0; mat[1][1]=1; mat[1][2]=0; mat[1][3]=0;
    mat[2][0]=0; mat[2][1]=0; mat[2][2]=1; mat[2][3]=0;
    mat[3][0]=0; mat[3][1]=0; mat[3][2]=0; mat[3][3]=1;
}

void TR_Translate(float matrix[4][4],float tx,float ty,float tz)
{
   float tmat[4][4];
   tmat[0][0]=1;  tmat[0][1]=0;  tmat[0][2]=0;  tmat[0][3]=0;
   tmat[1][0]=0;  tmat[1][1]=1;  tmat[1][2]=0;  tmat[1][3]=0;
   tmat[2][0]=0;  tmat[2][1]=0;  tmat[2][2]=1;  tmat[2][3]=0;
   tmat[3][0]=tx; tmat[3][1]=ty; tmat[3][2]=tz; tmat[3][3]=1;
   MAT_Mult(matrix,tmat,mat1);
   MAT_Copy(mat1,matrix);
}

void TR_Scale(float matrix[4][4],float sx,float sy, float sz)
{
   float smat[4][4];
   smat[0][0]=sx; smat[0][1]=0;  smat[0][2]=0;  smat[0][3]=0;
   smat[1][0]=0;  smat[1][1]=sy; smat[1][2]=0;  smat[1][3]=0;
   smat[2][0]=0;  smat[2][1]=0;  smat[2][2]=sz; smat[2][3]=0;
   smat[3][0]=0;  smat[3][1]=0;  smat[3][2]=0;  smat[3][3]=1;
   MAT_Mult(matrix,smat,mat1);
   MAT_Copy(mat1,matrix);
}

void TR_Rotate(float matrix[4][4],int ax,int ay,int az)
{
   float xmat[4][4], ymat[4][4], zmat[4][4];
   xmat[0][0]=1;        xmat[0][1]=0;        xmat[0][2]=0;        xmat[0][3]=0;
   xmat[1][0]=0;        xmat[1][1]=COS(ax);  xmat[1][2]=SIN(ax);  xmat[1][3]=0;
   xmat[2][0]=0;        xmat[2][1]=-SIN(ax); xmat[2][2]=COS(ax);  xmat[2][3]=0;
   xmat[3][0]=0;        xmat[3][1]=0;        xmat[3][2]=0;        xmat[3][3]=1;

   ymat[0][0]=COS(ay);  ymat[0][1]=0;        ymat[0][2]=-SIN(ay); ymat[0][3]=0;
   ymat[1][0]=0;        ymat[1][1]=1;        ymat[1][2]=0;        ymat[1][3]=0;
   ymat[2][0]=SIN(ay);  ymat[2][1]=0;        ymat[2][2]=COS(ay);  ymat[2][3]=0;
   ymat[3][0]=0;        ymat[3][1]=0;        ymat[3][2]=0;        ymat[3][3]=1;

   zmat[0][0]=COS(az);  zmat[0][1]=SIN(az);  zmat[0][2]=0;        zmat[0][3]=0;
   zmat[1][0]=-SIN(az); zmat[1][1]=COS(az);  zmat[1][2]=0;        zmat[1][3]=0;
   zmat[2][0]=0;        zmat[2][1]=0;        zmat[2][2]=1;        zmat[2][3]=0;
   zmat[3][0]=0;        zmat[3][1]=0;        zmat[3][2]=0;        zmat[3][3]=1;

   MAT_Mult(matrix,ymat,mat1);
   MAT_Mult(mat1,xmat,mat2);
   MAT_Mult(mat2,zmat,matrix);
}
*/

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

int 	main(int argc, 	char **argv)
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
	world.fd = open(world.file, O_RDONLY);
	read_file(&world);
	close(world.fd);

	world.mlx = mlx_init();
	world.window = mlx_new_window(world.mlx, world.wwidth, world.wheight, world.file);
	get_wh(&world);
	set_scale(&world);
	init_cam(&world);

	//mlx_key_hook(world.window, keydown_hook, &world);
	mlx_hook(world.window, 2, 0, key_pressed_hook, &world);
	render(&world);
	//mlx_clear_window(world.mlx, world.window);

	mlx_loop(world.mlx);
	return 0;
}