/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:09:07 by lgaducew          #+#    #+#             */
/*   Updated: 2021/11/18 20:12:16 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# define __USE_GNU 1
# define __USE_POSIX 1
# define __USE_POSIX199309 1
# include <signal.h>
# include <sys/types.h>
//# include <stdbool.h>

# define SLP 1500
# define SIG0 SIGUSR1
# define SIG1 SIGUSR2

typedef struct s_mt
{
	pid_t	r_pid;
	pid_t	e_pid;
	int		*buff;

	int		bits;
}	t_mt;


#endif
