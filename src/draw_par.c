/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_par.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:55:27 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/19 14:06:00 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x_par(t_fdf *fdf, int x)
{
	return (fdf->startx + (fdf->scalx * x));
}

int		coord_y_par(t_fdf *fdf, int y, int z)
{
	return (fdf->starty + fdf->scaly * y - \
			(z * fdf->value) * fdf->scalx);
}

void	draw_x_par(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < (fdf->nbr_ligne - 1))
	{
		x = 0;
		while (x < fdf->nbr_point[y] && (fdf->nbr_point[y + 1] - x) > 0)
		{
			fdf->x1 = coord_x_par(fdf, x);
			fdf->y1 = coord_y_par(fdf, y, fdf->nbr[y][x]);
			fdf->color2 = fdf->nbr[y][x];
			fdf->x2 = coord_x_par(fdf, x);
			fdf->y2 = coord_y_par(fdf, y + 1, fdf->nbr[y + 1][x]);
			fdf->color1 = fdf->nbr[y + 1][x];
			bresenham(fdf);
			x++;
		}
		y++;
	}
}

void	draw_y_par(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->nbr_ligne)
	{
		x = 0;
		while (x < (fdf->nbr_point[y] - 1))
		{
			fdf->x1 = coord_x_par(fdf, x);
			fdf->y1 = coord_y_par(fdf, y, fdf->nbr[y][x]);
			fdf->color2 = fdf->nbr[y][x];
			x++;
			fdf->x2 = coord_x_par(fdf, x);
			fdf->y2 = coord_y_par(fdf, y, fdf->nbr[y][x]);
			fdf->color1 = fdf->nbr[y][x];
			bresenham(fdf);
		}
		y++;
	}
}

int		print_point_par(t_fdf *fdf)
{
	fdf->pos = 1;
	draw_x_par(fdf);
	draw_y_par(fdf);
	return (1);
}
