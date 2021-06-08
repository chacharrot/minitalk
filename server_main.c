
#include "./libft/libft.h"
#include "minitalk.h"
#include <stdio.h>

void		*s_mlc(void *index)
{
	if (index == NULL)
		index = malloc(4);
	return (index);
}

void		get_bit(int sig)
{
	char		i;
	static int	size;
	static char	output;

	if (sig == SIGUSR1)
		i = 1;
	else
		i = 0;
	output += i << size;
	size++;
	if ((size) == 8)
	{
		ft_putchar(output);
		size = 0;
		output = 0;
	}
}

int			main(void)
{
	write(1, "pid : ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, get_bit);
		signal(SIGUSR2, get_bit);
		pause();
	}
	return (0);
}
