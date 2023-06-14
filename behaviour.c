/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:54:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/14 15:09:30 by jonahkollne      ###   ########.fr       */
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
		pthread_mutex_lock(param->mutex);
		alive = rand() % 10;
		// check if myself is alive (t_eat, t_die etc..)
		status_print(&(param->person), param->print_mutex);
		pthread_mutex_unlock(param->mutex);
	}
	return (args);
}
