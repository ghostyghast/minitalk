/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:57:52 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/31 15:22:00 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig_num, siginfo_t *info, void *other)
{
	static int				i = 0;
	static char				c = 0;

	(void)other;
	c |= (sig_num == ONE);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(info->si_pid, ONE);
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		kill(info->si_pid, ZERO);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sig_act;

	ft_printf("Hi :-) this is my pid :%i\n", getpid());
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_sigaction = handler;
	sigaction(ZERO, &sig_act, 0);
	sigaction(ONE, &sig_act, 0);
	while (1)
		pause();
	return (0);
}
