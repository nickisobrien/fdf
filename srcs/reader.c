/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/16 13:27:54 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		read_file(t_world *w)
{
	char	*s;
	char	*ptr;
	t_point *head;
	t_point *new_point;
	t_point *trav;

	head = init_point(0, 0, 0, 0);
	w->point_lst = head;
	w->rows = -1;
	while ((get_next_line(w->fd, &s) > 0) && ++(w->rows) >= 0 && !(w->cols = 0))
	{
		ptr = s;
		while (*s)
		{
			if ((ft_isdigit(*s) || *s == '-') && (trav = head))
			{
				new_point = init_point(w->cols++, w->rows, ft_atoi(s), 0);
				while (trav->next)
					trav = trav->next;
				trav->next = new_point;
				while (*(s + 1) == '-' || ft_isalnum(*(s + 1))
					|| *(s + 1) == ',')
					s++;
			}
			s++;
		}
		free(ptr);
	}
	//free(s);
	w->point_lst = w->point_lst->next + (w->rows++ * 0);
	free(head);
}
