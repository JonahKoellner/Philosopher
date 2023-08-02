/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/16 10:35:55 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	*print_activity(t_activity activity)
{
	if (activity == EAT)
		return ("Eating");
	else if (activity == SLEEP)
		return ("Sleeping");
	else if (activity == THINK)
		return ("THONK");
	else
		return (NULL);
	return (NULL);
}

int	status_print(t_person *philosoper, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf("---\t---\t---------\t\t-\n");
	printf("|MS\t\t|NR\t|Activity\t|\n");
	printf("|%ld\t", time(NULL));
	printf("|%d\t", philosoper->nr);
	printf("|%s\t\t|\n", print_activity(philosoper->active));
	pthread_mutex_unlock(print_mutex);
	return (0);
}
