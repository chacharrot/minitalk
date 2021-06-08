/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:58:51 by scha              #+#    #+#             */
/*   Updated: 2021/06/08 16:27:32 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char			arr[11];
	char			*base;
	int				count;
	long int		nb2;

	if (nb == 0)
		write(1, "0", 1);
	nb2 = nb;
	base = "0123456789";
	if (nb < 0)
	{
		nb2 = nb2 * -1;
		write(1, "-", 1);
	}
	count = 0;
	while (nb2 > 0)
	{
		arr[count] = base[nb2 % 10];
		nb2 = nb2 / 10;
		count++;
	}
	while (count > 0)
		write(1, &arr[--count], 1);
}