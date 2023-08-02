/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:54:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/02 11:20:22 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_mind(void	*args)
{
	t_param	*param;
	int		alive;

	alive = 1;
	param = (t_param *)args;
	while (alive)
	{
		printf("Beginning of philo brain %d using forks\nf1:%d\tf2:%d\n",
		param->person.nr, param->person.fork1, param->person.fork2);
		break;
		// if (param->person.perso.hunger > 0
			// && param->person.eaten < param->person.perso.hunger)
		if (!pthread_mutex_lock(param->forks[param->person.fork1]
				&& !pthread_mutex_lock(param->forks[param->person.fork2])))
			// GOT THE FORKS

		/*
		Bahviour:
			if (hunger < time_philo_has_to_eat)
				if (try to get the fork to eat)
					sleep(time_to_eat)
			sleep(time_to_sleep)
			set_state_activity = thinking

		*/
	}
	return (args);
}
