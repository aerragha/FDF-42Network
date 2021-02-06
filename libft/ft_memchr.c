/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:23:46 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/06 14:41:07 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	c2;

	i = 0;
	p = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == c2)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
