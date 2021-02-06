/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:58:51 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/19 14:00:14 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_check(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->pos == 1)
		print_point_par(fdf);
	else
		print_point(fdf);
}

void	projec_key(int key, t_fdf *fdf)
{
	if (!fdf)
		exit(1);
	else if (key == 35)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		fdf->startx = 750;
		fdf->starty = 100;
		print_point_par(fdf);
	}
	else if (key == 34)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		fdf->startx = 950;
		fdf->starty = 250;
		print_point(fdf);
	}
}

void	zoom_key(int key, t_fdf *fdf)
{
	if (!fdf)
		exit(1);
	else if (key == 88)
	{
		fdf->scalx++;
		fdf->scaly++;
		clear_check(fdf);
	}
	else if (key == 85)
	{
		fdf->scalx--;
		fdf->scaly--;
		clear_check(fdf);
	}
}

void	value_key(int key, t_fdf *fdf)
{
	if (!fdf)
		exit(1);
	else if (key == 87)
	{
		fdf->value += 0.1;
		clear_check(fdf);
	}
	else if (key == 84)
	{
		fdf->value -= 0.1;
		clear_check(fdf);
	}
}

void	drow_key(int key, t_fdf *fdf)
{
	if (!fdf)
		exit(1);
	else if (key == 124)
	{
		fdf->startx += 10;
		clear_check(fdf);
	}
	else if (key == 123)
	{
		fdf->startx -= 10;
		clear_check(fdf);
	}
	else if (key == 125)
	{
		fdf->starty += 10;
		clear_check(fdf);
	}
	else if (key == 126)
	{
		fdf->starty -= 10;
		clear_check(fdf);
	}
}
