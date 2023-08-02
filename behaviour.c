/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:54:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/07/27 10:08:00 by jonahkollne      ###   ########.fr       */
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

		/**
		 * Behaviour:
		 	* alive bahvoiur is being decided by how long it was since last eaten
			if last_eaten.time() - now.time() <= param->person.t_eat
				// still alive */
				//try to eat (if you still need to (hunger given))
				//pthread_mutex_lock(param->forks[param->person.nr]);
				//pthread_mutex_lock(param->forks[param->person.nr + 1]);
			//		take forks and lock them.
			//		sleep for the time after eating
			//	if not than think
			//else
				// died
		//*/


		//pthread_mutex_lock(param->forks[param->person.nr]);
		//alive = rand() % 10;
		// check if myself is alive (t_eat, t_die etc..)
		//status_print(&(param->person), param->print_mutex);
		//pthread_mutex_unlock(param->person.nr);
	}
	return (args);
}
