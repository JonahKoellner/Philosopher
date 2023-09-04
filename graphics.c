/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/04 09:47:53 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	*print_activity(t_activity activity)
{
	if (activity == EAT)
		return ("eating");
	else if (activity == SLEEP)
		return ("sleeping");
	else if (activity == THINK)
		return ("thinking");
	else
		return ("");
}

int	status_print(t_person *philo, pthread_mutex_t *print_mutex, t_activity new)
{
	pthread_mutex_lock(print_mutex);
	if (new == TAKEN)
		printf("%lld %d has taken a fork\n", get_time_ms(),
			philo->nr);
	else
	{
		philo->active = new;
		printf("%p\n", philo);
		printf("%lld %d is %s\n", get_time_ms(),
			philo->nr, print_activity(philo->active));
	}
	pthread_mutex_unlock(print_mutex);
	return (0);
}
