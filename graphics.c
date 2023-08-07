/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/07 17:46:03 by jkollner         ###   ########.fr       */
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

int	status_print(t_person *philosoper, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf("%lld %d is %s\n", get_time_ms(),
		philosoper->nr, print_activity(philosoper->active));
	pthread_mutex_unlock(print_mutex);
	return (0);
}
