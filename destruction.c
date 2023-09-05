/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:49:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/05 09:02:47 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	still_eating(t_universe *universe, int pn)
{
	int	index;

	index = 0;
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
		pthread_join(*universe->humanity[index].soul, NULL);
		free(universe->humanity[index].soul);
		index++;
	}
	free(universe->death);
	index = 0;
	while (index < pn)
		free(params[index++]);
	free(params);
	free(universe->mutexe.forks);
	free(universe->mutexe.death);
	free(universe->mutexe.print);
	free(universe->mutexe.var_access);
	free(universe->humanity);
	free(universe);
	return (0);
}
