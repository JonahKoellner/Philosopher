/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:54:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/02 16:03:21 by jkollner         ###   ########.fr       */
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
		if (!pthread_mutex_lock(param->forks[param->person.fork1])
			&& (!pthread_mutex_lock(param->forks[param->person.fork2])))
		{
			status_print(&param->person, param->print_mutex);
			usleep(10000);
			pthread_mutex_unlock(param->forks[param->person.fork2]);
			pthread_mutex_unlock(param->forks[param->person.fork1]);
		}
	}
	return (args);
}
