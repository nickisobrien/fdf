/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:47:14 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/15 17:23:07 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_close(void)
{
	exit(0);
}

void	ft_error(void)
{
	ft_putendl("error: invalid file");
	exit(0);
}

void	ft_usage(void)
{
	ft_putendl("usage: ./fdf file");
	exit(-1);
}
