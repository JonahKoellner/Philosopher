/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:55:10 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/18 10:29:09 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	finished_eating(t_person *humans, int max)
{
	int	index;

	index = 0;
	while (index < max)
	{
		if (humans[index].stomach.times_eaten
			== humans[index].perso.hunger)
			return (1);
		index++;
	}
	return (0);
}

int	death(int *death, t_person *humans, pthread_t *souls, int index)
{
	int	iter;

	while (*death == 0 && !finished_eating(humans, index))
	{
		sleep_ms(1);
	}
	iter = 0;
	if (*death == 1)
	{
		// while (iter < index)
		// 	pthread_detach(souls[iter++]);
		while (iter < index)
			pthread_join(souls[iter++], NULL);
	}
	return (0);
}
