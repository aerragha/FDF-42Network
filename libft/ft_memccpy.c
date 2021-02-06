/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:47:07 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/06 13:53:55 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_d;
	unsigned char	*p_s;

	p_d = (unsigned char*)dst;
	p_s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		p_d[i] = p_s[i];
		if (p_d[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
