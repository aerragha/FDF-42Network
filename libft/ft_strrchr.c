/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:31:27 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/05 18:01:15 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char *chaine;

	chaine = 0;
	while (*str)
	{
		if (*str == c)
			chaine = (char*)str;
		str++;
	}
	if (chaine)
		return (chaine);
	if (c == '\0')
		return ((char*)str);
	return (0);
}
