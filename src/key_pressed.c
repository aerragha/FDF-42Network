/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:14:17 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/19 14:00:05 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pressed(int key, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (key == 53)
		exit(1);
	else if (key == 82)
	{
		if (fdf->col2 == 0xFFFFFF)
			fdf->col2 = 0x000000;
		else
			fdf->col2 = 0xFFFFFF;
		clear_check(fdf);
	}
	else if (key == 49)
	{
		fdf->scalx = 2;
		fdf->scaly = 2;
		clear_check(fdf);
	}
	drow_key(key, fdf);
	value_key(key, fdf);
	zoom_key(key, fdf);
	projec_key(key, fdf);
	return (0);
}
