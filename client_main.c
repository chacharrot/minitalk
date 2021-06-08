#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <stdio.h>

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
		if (argv[1][i] < '0' && argv[1][i] >'9')
			error("input");
		i++;
	}
}

static void	send_bit_to_sever(char *pidc, char *str)
{
	int	pid;
	int	shift;
	int	i;
	unsigned char j;
	
	pid = ft_atoi(pidc);
	i = 0;
	while (str[i])
	{
		shift = 8;
		while (shift)
		{
			if (str[i] & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					error("pid");
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					error("pid");
			str[i] >>= 1;
			shift--;
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		check_argv(argv);
		send_bit_to_sever(argv[1], argv[2]);
	}
	else
	{
		write(2, "wrong input\n", 12);
		exit(1);
	}
	return (1);
}