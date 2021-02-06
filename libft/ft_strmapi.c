/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:23:11 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/15 19:07:15 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned	int	i;
	char			*new;

	i = 0;
	if (!s || !(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
