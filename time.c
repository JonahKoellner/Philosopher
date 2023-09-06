/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:02:06 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 06:08:33 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_time_ms(void)
{
	struct timeval	t_val;

	if (gettimeofday(&t_val, NULL) == -1)
		return (printf("Time Error\n"), 0);
	return ((long long)t_val.tv_sec * 1000 + t_val.tv_usec / 1000);
}

int	sleep_ms_death(int ms, t_param *resource)
{
	long long	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < ms)
	{
		if (access_value(resource->mutexe.death, resource->death) == 1)
			break ;
		usleep(500);
	}
	return (0);
}

int	sleep_ms(int ms)
{
	long long	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < ms)
	{
		usleep(500);
	}
	return (0);
}
