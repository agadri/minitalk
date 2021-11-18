/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:56:51 by lgaducew          #+#    #+#             */
/*   Updated: 2021/11/18 21:02:12 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*reply_master(char byte)
{
	if (byte == SIG1)
		printf("1\n");
	if (byte == SIG0)
		printf("0\n");
	return (NULL);
}

void	translate(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIG0)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			printf("\n");
		else
			printf("c -> %c\n", c);
		c = 0;
		i = 0;
	}
}


void	reply(int sig, siginfo_t *info, void *mt)
{
	(void)mt;
	
	if (sig == SIG1)
	{
		reply_master(SIG1);
		usleep(SLP);
		kill(info->si_pid, SIG1);
	}
	else if (sig == SIG0)
	{
		reply_master(SIG0);
		usleep(SLP);
		kill(info->si_pid, SIG0);
	}
	translate(sig);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;
	t_mt	mt;

	pid = 0;
	pid = getpid();
	//memset(&a, 0, sizeof(a));
	memset(&mt, 0, sizeof(mt));
	printf(" pd %d\n", pid);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &reply; 
	sigaction(SIG1, &sig, 0);
	sigaction(SIG0, &sig, 0);
	while (1)
		;
	return (EXIT_SUCCESS);
}
// y : 01111001
// a : 01100001
