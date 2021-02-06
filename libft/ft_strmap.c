/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:15:04 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/15 19:06:54 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned	int	i;
	char			*new;

	i = 0;
	if (!s || !(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
