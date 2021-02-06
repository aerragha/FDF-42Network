/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:43:30 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/19 13:29:33 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cas_neg(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;

	fdf->i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0x8E24AA);
	e = (2 * fdf->dy) - fdf->dx;
	inc1 = 2 * (fdf->dy - fdf->dx);
	inc2 = 2 * fdf->dy;
	while (fdf->i < fdf->dx)
	{
		if (e >= 0)
		{
			fdf->y1 = fdf->y1 + fdf->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->x1 = fdf->x1 + fdf->incx;
		if (fdf->color1 > 0 || fdf->color2 > 0)
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0x8E24AA);
		else
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, fdf->col2);
		(fdf->i)++;
	}
}

void	cas_pos(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;

	fdf->i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0x8E24AA);
	e = (2 * fdf->dx) - fdf->dy;
	inc1 = 2 * (fdf->dx - fdf->dy);
	inc2 = 2 * fdf->dx;
	while (fdf->i < fdf->dy)
	{
		if (e >= 0)
		{
			fdf->x1 = fdf->x1 + fdf->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->y1 = fdf->y1 + fdf->incy;
		if (fdf->color1 > 0 || fdf->color2 > 0)
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0x8E24AA);
		else
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, fdf->col2);
		(fdf->i)++;
	}
}

void	bresenham(t_fdf *fdf)
{
	fdf->dx = fdf->x2 - fdf->x1;
	fdf->dy = fdf->y2 - fdf->y1;
	fdf->dx = abs(fdf->dx);
	fdf->dy = abs(fdf->dy);
	fdf->incx = (fdf->x2 > fdf->x1) ? 1 : -1;
	fdf->incy = (fdf->y2 > fdf->y1) ? 1 : -1;
	if (fdf->dx > fdf->dy)
		cas_neg(fdf);
	else
		cas_pos(fdf);
}
