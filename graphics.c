/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/07 13:15:56 by jkollner         ###   ########.fr       */
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
		return ("Thinking");
	else
		return ("");
	return ("");
}

int	status_print(t_person *philosoper, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf("%lld %d is %s\n", get_time_ms(), philosoper->nr, print_activity(philosoper->active));
	pthread_mutex_unlock(print_mutex);
	return (0);
}
