/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerragha <zeehindi@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:04:52 by aerragha          #+#    #+#             */
/*   Updated: 2018/10/15 18:32:41 by aerragha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned	int	res;
	unsigned	int	neg;

	neg = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * neg);
}
