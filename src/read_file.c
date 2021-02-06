/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:13:56 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/19 13:08:20 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_ligne(t_fdf *fdf, int fd)
{
	char	*line;

	fdf->nbr_ligne = 0;
	while (get_next_line(fd, &line) == 1)
		(fdf->nbr_ligne)++;
	close(fd);
}

int		count_point(char **split, t_fdf *fdf)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	if (fdf->l == 0)
	{
		fdf->len = i;
		fdf->l = 1;
	}
	return (i);
}

char	*fdf_to_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		if (str[i] && str[i] == ',' && str[i + 1] == '0')
			while (str[i] && str[i] != ' ')
			{
				str[i] = ' ';
				i++;
			}
		if (str[i] && ft_isdigit(str[i]) == 0)
			str[i] = ' ';
		i++;
	}
	return (str);
}

int		ft_getnbr(char *str)
{
	int		ret;

	if (*str == '-')
		return (-ft_getnbr(str + 1));
	if (*str == '+')
		return (ft_getnbr(str + 1));
	ret = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret = ret + *str - '0';
		str++;
	}
	return (ret);
}

void	read_file(t_fdf *fdf, int fd)
{
	if ((!(fdf->nbr = (int **)malloc(sizeof(int *) * fdf->nbr_ligne))) ||
		(!(fdf->nbr_point = (int *)malloc(sizeof(int) * fdf->nbr_ligne))))
		exit(1);
	while (get_next_line(fd, &(fdf->ligne)) == 1)
	{
		if (fdf->ligne)
		{
			fdf->i = 0;
			fdf->ligne = fdf_to_space(fdf->ligne);
			fdf->split = ft_strsplit(fdf->ligne, ' ');
			fdf->nbr_point[fdf->k] = count_point(fdf->split, fdf);
			check_help(fdf);
			if (!(fdf->nbr[fdf->j] = (int *)malloc(sizeof(int) * \
							fdf->nbr_point[fdf->k])))
				exit(1);
			while (fdf->split[fdf->i])
			{
				fdf->nbr[fdf->j][fdf->i] = ft_getnbr(fdf->split[fdf->i]);
				(fdf->i)++;
			}
			free(fdf->split);
			(fdf->j)++;
			(fdf->k)++;
		}
	}
}
