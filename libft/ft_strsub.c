/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:59:02 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/08 16:36:37 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s || !(sub = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
