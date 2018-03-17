/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:47:14 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/16 18:20:19 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_close(void)
{
	exit(0);
}

void	ft_error()
{
	perror("Error ");
	exit(0);
}

void	ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename>");
	exit(-1);
}
