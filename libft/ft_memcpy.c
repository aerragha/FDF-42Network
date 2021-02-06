/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:30:07 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/15 15:21:40 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*p2;
	int				i;

	p = (unsigned char*)dst;
	p2 = (unsigned char*)src;
	i = 0;
	while (n-- > 0)
	{
		p[i] = p2[i];
		i++;
	}
	return (dst);
}
