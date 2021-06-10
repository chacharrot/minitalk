/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:07:33 by scha              #+#    #+#             */
/*   Updated: 2021/06/10 16:51:04 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int minus;
	int num;

	num = 0;
	minus = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str <= '9' && *str >= '0' && *str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * minus);
}
