/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:26:30 by aerragha          #+#    #+#             */
/*   Updated: 2018/12/01 14:35:32 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split(char **s, char **line, int fd)
{
	int len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		s[fd] = ft_strdup(s[fd] + len + 1);
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *s[255];
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		s[fd] = ft_strjoin(s[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (split(s, line, fd));
}
