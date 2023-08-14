/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:55:10 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/14 09:33:28 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	finished_eating(t_person *universe, int max)
{
	int	index;

	index = 0;
	while (index < max)
	{
		if (universe[index].stomach.times_eaten
			== universe[index].perso.hunger)
			return (1);
		index++;
	}
	return (0);
}

int	death(int *death, t_person *universe, pthread_t *souls, int index)
{
	while (*death == 0 && !finished_eating(universe, index))
		sleep_ms(1);
	if (*death == 1)
	{
		while (*souls)
		{
			pthread_detach(*souls);
			souls++;
		}
	}
	return (0);
}
