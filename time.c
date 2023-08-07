/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:02:06 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/07 13:21:09 by jkollner         ###   ########.fr       */
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

int	sleep_ms(int ms)
{
	int	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < ms)
		usleep(500);
	return (0);
}
