/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:35:01 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/16 10:17:11 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned int	start;
	size_t			end;

	if (!(s))
		return (0);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if ((end = ft_strlen(s)))
		end--;
	while (end > 0 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if (end == 0)
		return ((char *)ft_memalloc(sizeof(char)));
	return (ft_strsub(s, start, end - start + 1));
}
