/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:31:43 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 06:02:44 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	print_activity(t_param *resource, int nr, char *activity, long long int t)
{
	pthread_mutex_lock(resource->mutexe.print);
	if (access_value(resource->mutexe.death, resource->death) == 0)
	{
		printf("%lld\t %d %s\n", t - resource->create_moment, nr, activity);
	}
	pthread_mutex_unlock(resource->mutexe.print);
	return (0);
}
