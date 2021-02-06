/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:51:46 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/27 15:57:33 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str);
}
