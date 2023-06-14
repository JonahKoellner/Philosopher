/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/14 15:07:27 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	print_activity(t_activity activity)
{
	if (activity == EAT)
		printf("Eating\n");
	else if (activity == SLEEP)
		printf("Sleeping\n");
	else if (activity == THINK)
		printf("THONK\n");
	else
		return (0);
	return (1);
}

int	status_print(t_person *philosoper, pthread_mutex_t *print_mutex)
{
	// close mutex
	pthread_mutex_lock(print_mutex);

	// print out the status and the time of the philosopher
		// things to print:
			// time
			// nr
			// hunger
			// print_activity
		printf("NR: %d\t", philosoper->nr);
		print_activity(philosoper->active);
	// open mutex and return
	pthread_mutex_unlock(print_mutex);
	return (0);
}
