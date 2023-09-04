/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:31:43 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/04 19:37:40 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	print_activity(t_param *resource, int nr, char *activity, long long int t)
{
	if (access_value(resource->mutexe.death, resource->death) == 0)
	{
		pthread_mutex_lock(resource->mutexe.print);
		printf("%lld %d %s\n", t, nr, activity);
		pthread_mutex_unlock(resource->mutexe.print);
	}
	return (0);
}
