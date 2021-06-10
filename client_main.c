/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:00:48 by scha              #+#    #+#             */
/*   Updated: 2021/06/10 18:10:27 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"

static void	error(char *str)
{
	ft_putstr("wrong ");
	ft_putstr(str);
	exit(1);
}

static void	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			error("pid");
		i++;
	}
}

void		send_bit_sever(char *pidc, char *str)
{
	int				pid;
	int				shift;
	int				i;

	pid = ft_atoi(pidc);
	i = -1;
	while (str[++i])
	{
		shift = 8;
		while (shift--)
		{
			if (str[i] & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					error("pid");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error("pid");
			}
			str[i] >>= 1;
			usleep(200);
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc == 3)
	{
		check_argv(argv);
		send_bit_sever(argv[1], argv[2]);
	}
	else
		error("input");
	return (1);
}
