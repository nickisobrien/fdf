/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/16 18:15:35 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		read_line(t_world *world, char *s)
{
	t_point	*trav;
	t_point	*new_point;
	int		cols;

	cols = 0;
	while (*s)
	{
		if ((ft_isdigit(*s) || *s == '-'))
		{
			trav = world->point_lst;
			new_point = init_point(cols++,
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
	if (world->cols == 0)
		world->cols = cols;
	else if (world->cols != cols)
		ft_error();

}

void		read_file(t_world *w)
{
	char	*s;
	t_point *head;

	head = init_point(0, 0, 0, 0);
	w->point_lst = head;
	w->rows = -1;
	w->cols = 0;
	while ((get_next_line(w->fd, &s) > 0))
	{
		if (!*s)
			ft_error();
		(w->rows)++;
		read_line(w, s);
		free(s);
	}
	if (!w->point_lst->next)
		ft_error();
	w->point_lst = w->point_lst->next + (w->rows++ * 0);
	free(head);
}
