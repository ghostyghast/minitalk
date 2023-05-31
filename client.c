/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:57:58 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/31 15:22:28 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_recv(int sig)
{
	static int	received;

	if (sig == ZERO)
		++received;
	else
	{
		ft_printf("Received messages (characters) :[%i]\n", received);
		exit(0);
	}
}

void	send_string(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, ONE);
			else
				kill(pid, ZERO);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, ZERO);
		usleep(100);
	}
}

int	main(int c, char **str)
{
	if (c == 3)
	{
		signal(ZERO, sig_recv);
		signal(ONE, sig_recv);
		send_string(ft_atoi(str[1]), str[2]);
		while (1)
			pause();
		return (0);
	}
	else if (c < 3)
		ft_printf("not enough args\n");
	else
		ft_printf("too many args\n");
}
