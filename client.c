/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:55:54 by lgaducew          #+#    #+#             */
/*   Updated: 2021/11/18 19:11:56 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i += 1;
	return (i);
}

void     receive(int sig, siginfo_t *info, void *mt)
{
	(void)sig, (void)info, (void)mt;
	printf("i get%d\n", sig);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	struct sigaction	sig;
	int		i;
	int		len;
	int		bits;
	char	*str;

	str = NULL;
	memset(&pid, 0, sizeof(sig));
	printf("client pid: %d\n", getpid());
	if (ac != 3)
		return (EXIT_FAILURE);
	pid = atoi(av[1]);
	if (pid == 0)
		return (EXIT_FAILURE);
	str = av[2];
	i = 0;
	len = ft_strlen(str) + 1;
	bits = 0;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &receive;
	sigaction(SIG1, &sig, NULL);
	sigaction(SIG0, &sig, NULL);
	//printf("client..1..\n");
	while (i < len)
	{
		bits = 7;
		//printf("client..2..\n");
		while (bits >= 0)
		{
			usleep(SLP);
			//printf("client..3..\n");
			if ((str[i] >> bits) & 1)
			{
				printf("send : 1\n");
				kill(pid, SIG1);
			}
			else
			{
				printf("send : 0\n");
				kill(pid, SIG0);
			}
			pause();
			--bits;
		}
		++i;
	}
	return (EXIT_SUCCESS);
}