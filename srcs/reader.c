/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 11:30:12 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		get_wh(t_world *world)
{
	t_point *head;
	int maxX;
	int maxY;

	maxY = -2147483648;
	maxX = -2147483648;
	head = world->point_lst;
	while (head)
	{
		if (head->x > maxX)
			maxX = head->x;
		if (head->y > maxY)
			maxY = head->y;
		head = head->next;
	}
	maxX++;
	maxY++;
	world->cols = maxX;
	world->rows = maxY;
}

void	read_file(t_world *world)
{
	char *str;
	int line;
	int col;
	t_point *head;
	t_point *new_point;
	t_point *trav;

	head = init_point(0, 0, 0, 0);
	world->point_lst = head;
	line = 0;
	while ((get_next_line(world->fd, &str) > 0))
	{
		col = 0;
		while (*str)
		{
			if (ft_isdigit(*str) || *str == '-')
			{
				new_point = init_point(col, line, ft_atoi(str), 0);
				trav = head;
				while (trav->next)
					trav = trav->next;
				trav->next = new_point;

				while (ft_isdigit(*(str + 1)) || *(str + 1) == '-')
					str++;
				col++;
			}
			str++;
		}
		line++;
	}
	world->point_lst = head->next;
	free(head);
}