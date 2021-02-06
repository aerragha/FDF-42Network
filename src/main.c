/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:11:53 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/20 15:29:42 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

void	check_help(t_fdf *fdf)
{
	if (fdf->len > count_point(fdf->split, fdf))
		ft_error();
}

void	ft_error(void)
{
	ft_putstr("Found wrong line length. Exiting.\n");
	exit(EXIT_FAILURE);
}

void	initial(t_fdf *fdf)
{
	fdf->k = 0;
	fdf->j = 0;
	fdf->len = 0;
	fdf->l = 0;
	fdf->pos = 2;
	fdf->value = 0.1;
	fdf->scalx = 20;
	fdf->scaly = 20;
	fdf->startx = 950;
	fdf->starty = 350;
	fdf->col2 = 0xFFFFFF;
}

int		main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		count_ligne(&fdf, fd);
		fd = open(argv[1], O_RDONLY);
		initial(&fdf);
		read_file(&fdf, fd);
		close(fd);
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, 1920, 1080, "FDF aerragha");
		print_point(&fdf);
		mlx_hook(fdf.win, 2, 0, &key_pressed, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		ft_putstr("Usage ./fdf <filename>\n");
	return (0);
}
