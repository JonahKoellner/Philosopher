/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:49:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/04 19:37:24 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	still_eating(t_universe *universe, int pn)
{
	int	index;

	while (index < pn)
	{
		if (access_value(universe->mutexe.var_access,
				&universe->humanity[index].perso.eaten)
			< universe->humanity[0].perso.hunger)
			return (1);
		index++;
	}
	return (0);
}

int	the_end(t_universe *universe, int pn)
{
	while (access_value(universe->mutexe.death, universe->death) == 0
		&& still_eating(universe, pn) == 0)
	{
		sleep(1);
	}
	return (0);
}

int	big_rip(t_param **params, t_universe *universe, int pn)
{
	int	index;

	index = 0;
	while (index < pn)
	{
		free(universe->humanity[index].soul);
		pthread_join(*universe->humanity[index].soul, NULL);
		index++;
	}
	free(universe->death);
	index = 0;
	while (index < pn)
		free(params[index++]);
	free(params);
	pthread_mutex_destroy(universe->mutexe.death);
	pthread_mutex_destroy(universe->mutexe.print);
	pthread_mutex_destroy(universe->mutexe.var_access);
	free(universe->mutexe.forks);
	free(universe->mutexe.death);
	free(universe->mutexe.print);
	free(universe->mutexe.var_access);
	free(universe->humanity);
	free(universe);
	return (0);
}
