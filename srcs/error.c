/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:47:14 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 14:50:28 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_close(t_world *world)
{
	(void)world;
	exit(0);
}

void	ft_error(t_world *world)
{
	(void)world;
	ft_putendl("error: invalid file");
	exit(0);
}
