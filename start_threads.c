/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:24:06 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 06:22:34 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	small_bang(t_universe *universe, t_param **params, int index, int pn)
{
	int	it;

	it = 0;
	while (it < pn)
	{
		if (it < index)
			pthread_join(*universe->humanity[it].soul, NULL);
		free(universe->humanity[it].soul);
		it++;
	}
	if (params != NULL)
	{
		while (it < index)
			free(params[it++]);
		free(params);
	}
	free(universe->death);
	it = 0;
	free(universe->mutexe.forks);
	free(universe->mutexe.death);
	free(universe->mutexe.print);
	free(universe->mutexe.var_access);
	free(universe->humanity);
	free(universe);
	return (0);
}

t_param	**big_bang(t_universe *universe, int pn)
{
	int				index;
	t_param			**params;

	index = 0;
	params = ft_calloc(pn, sizeof(t_param *));
	if (params == NULL)
		return (small_bang(universe, NULL, 0, pn), NULL);
	universe->create_moment = get_time_ms();
	while (index < pn)
	{
		params[index] = ft_calloc(1, sizeof(t_param));
		if (params[index] == NULL)
			return (small_bang(universe, params, index, pn), NULL);
		params[index]->mutexe = universe->mutexe;
		params[index]->person = &universe->humanity[index];
		params[index]->death = universe->death;
		params[index]->create_moment = universe->create_moment;
		pthread_create(universe->humanity[index].soul, NULL, behaviour,
			params[index]);
		if (index % 2 == 0)
			sleep_ms(1);
		index++;
	}
	return (params);
}
