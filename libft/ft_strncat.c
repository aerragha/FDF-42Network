/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:18:59 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/08 15:10:46 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int		len;
	size_t	j;

	len = 0;
	j = 0;
	while (dest[len] != '\0')
		len++;
	while (src[j] != '\0' && j < nb)
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';
	return (dest);
}
