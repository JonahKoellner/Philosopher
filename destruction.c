/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:49:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/05 16:49:25 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	still_eating(t_universe *universe, int pn)
{
	int	index;

	index = 0;
	if (universe->humanity[0].perso.hunger == -1)
		return (0);
	while (index < pn)
	{
		if (access_value(universe->mutexe.var_access,
				&universe->humanity[index].perso.eaten)
			< universe->humanity[0].perso.hunger)
			return (0);
		index++;
	}
	return (1);
}

int	outside_death(t_universe *universe, int pn)
{
	int				index;
	long long int	now;

	index = 0;
	now = get_time_ms();
	while (index < pn)
	{
		if (((now - universe->create_moment)
				- access_value(universe->mutexe.var_access,
					&universe->humanity[index].perso.last_eaten)
				>= universe->humanity[index].perso.t_die))
		{
			set_value(universe->mutexe.death, universe->death, 1);
			pthread_mutex_lock(universe->mutexe.print);
			printf("%lld\t %d died\n", now - universe->create_moment, index + 1);
			pthread_mutex_unlock(universe->mutexe.print);
			return (1);
		}
		index++;
	}
	return (0);
}

int	the_end(t_universe *universe, int pn)
{
	while (outside_death(universe, pn) == 0
		&& access_value(universe->mutexe.death, universe->death) == 0
		&& still_eating(universe, pn) == 0)
	{
		usleep(500);
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
	pthread_mutex_destroy(universe->mutexe.forks);
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
