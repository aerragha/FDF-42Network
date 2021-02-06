/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:03:42 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/25 10:06:37 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x(t_fdf *fdf, int x, int y)
{
	return ((fdf->startx - (fdf->scalx * y) + (fdf->scalx * x)) * \
			cos(0.523599));
}

int		coord_y(t_fdf *fdf, int x, int y, int z)
{
	return ((fdf->starty + ((fdf->scaly * x) + (fdf->scaly * y))) * \
			sin(0.523599) - (z * fdf->value) * fdf->scalx);
}

void	draw_x(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < (fdf->nbr_ligne - 1))
	{
		x = 0;
		while (x < fdf->nbr_point[y] && (fdf->nbr_point[y + 1] - x) > 0)
		{
			fdf->x1 = coord_x(fdf, x, y);
			fdf->y1 = coord_y(fdf, x, y, fdf->nbr[y][x]);
			fdf->color2 = fdf->nbr[y][x];
			fdf->x2 = coord_x(fdf, x, y + 1);
			fdf->y2 = coord_y(fdf, x, y + 1, fdf->nbr[y + 1][x]);
			fdf->color1 = fdf->nbr[y + 1][x];
			bresenham(fdf);
			x++;
		}
		y++;
	}
}

void	draw_y(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->nbr_ligne)
	{
		x = 0;
		while (x < (fdf->nbr_point[y] - 1))
		{
			fdf->x1 = coord_x(fdf, x, y);
			fdf->y1 = coord_y(fdf, x, y, fdf->nbr[y][x]);
			fdf->color2 = fdf->nbr[y][x];
			x++;
			fdf->x2 = coord_x(fdf, x, y);
			fdf->y2 = coord_y(fdf, x, y, fdf->nbr[y][x]);
			fdf->color1 = fdf->nbr[y][x];
			bresenham(fdf);
		}
		y++;
	}
}

int		print_point(t_fdf *fdf)
{
	fdf->pos = 2;
	draw_x(fdf);
	draw_y(fdf);
	return (1);
}
