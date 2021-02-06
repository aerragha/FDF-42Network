/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:13:11 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/20 15:29:20 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef	struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			nbr_ligne;
	int			**nbr;
	int			*nbr_point;
	char		*ligne;
	char		**split;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			incx;
	int			incy;
	int			scalx;
	int			scaly;
	int			startx;
	int			starty;
	float		value;
	int			color1;
	int			color2;
	int			col2;
	int			pos;
	int			i;
	int			j;
	int			k;
	int			len;
	int			l;
}				t_fdf;

int				ft_isdigit(int c);
void			count_ligne(t_fdf *fdf, int fd);
int				count_point(char **split, t_fdf *fdf);
char			*fdf_to_space(char *str);
int				ft_getnbr(char *str);
void			read_file(t_fdf *fdf, int fd);
void			initial(t_fdf *fdf);
void			bresenham(t_fdf *fdf);
void			cas_pos(t_fdf *fdf);
void			cas_neg(t_fdf *fdf);
int				coord_x(t_fdf *fdf, int x, int y);
int				coord_y(t_fdf *fdf, int x, int y, int z);
void			draw_x(t_fdf *fdf);
void			draw_y(t_fdf *fdf);
int				print_point(t_fdf *fdf);
int				coord_x_par(t_fdf *fdf, int x);
int				coord_y_par(t_fdf *fdf, int y, int z);
void			draw_x_par(t_fdf *fdf);
void			draw_y_par(t_fdf *fdf);
int				print_point_par(t_fdf *fdf);
int				key_pressed(int key, void *param);
void			clear_check(t_fdf *fdf);
void			projec_key(int key, t_fdf *fdf);
void			zoom_key(int key, t_fdf *fdf);
void			value_key(int key, t_fdf *fdf);
void			drow_key(int key, t_fdf *fdf);
void			ft_error(void);
void			check_help(t_fdf *fdf);

#endif
