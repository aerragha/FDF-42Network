/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:33:30 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/13 14:00:13 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t			num_sub(const char *s, char c, size_t *j)
{
	size_t	count;
	size_t	i;
	int		split;

	*j = 0;
	count = 1;
	i = 0;
	split = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			split = 1;
		else if (split)
		{
			count++;
			split = 0;
		}
		i++;
	}
	return (sizeof(char *) * count);
}

char					**ft_strsplit(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;

	if (!s || !(result = ft_memalloc(num_sub(s, c, &i))))
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			if ((len = (size_t)ft_strchr(s, c)))
			{
				result[i++] = ft_strsub(s, 0, len - (size_t)s);
				s = (const char *)len;
			}
			else
			{
				result[i++] = ft_strsub(s, 0, ft_strlen(s));
				break ;
			}
		}
	}
	return (result);
}
