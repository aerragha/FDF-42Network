/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:22:45 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/08 15:27:09 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = b;
	while (len > 0)
	{
		ch[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (ch);
}
