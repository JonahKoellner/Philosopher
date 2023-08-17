/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/17 20:25:56 by jonahkollne      ###   ########.fr       */
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
	philo->active = new;
	printf("%lld %d is %s\n", get_time_ms(),
		philo->nr, print_activity(philo->active));
	pthread_mutex_unlock(print_mutex);
	return (0);
}
