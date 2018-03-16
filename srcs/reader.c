/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/16 14:48:12 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		read_line(t_world *world, char *s)
{
	t_point	*trav;
	t_point	*new_point;

	while (*s)
	{
		if ((ft_isdigit(*s) || *s == '-'))
		{
			trav = world->point_lst;
			new_point = init_point(world->cols++,
				world->rows, ft_atoi(s), 0);
			while (trav->next)
				trav = trav->next;
			trav->next = new_point;
			while (*(s + 1) == '-' || ft_isalnum(*(s + 1))
				|| *(s + 1) == ',')
				s++;
		}
		s++;
	}
}

void		read_file(t_world *w)
{
	char	*s;
	t_point *head;

	head = init_point(0, 0, 0, 0);
	w->point_lst = head;
	w->rows = -1;
	while ((get_next_line(w->fd, &s) > 0) && ++(w->rows) >= 0 && !(w->cols = 0))
	{
		read_line(w, s);
		free(s);
	}
	w->point_lst = w->point_lst->next + (w->rows++ * 0);
	free(head);
}
