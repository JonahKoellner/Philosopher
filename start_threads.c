/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:24:06 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/04 19:44:31 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_param	**big_bang(t_universe *universe, int pn)
{
	int		index;
	t_param	**params;

	index = 0;
	params = ft_calloc(pn, sizeof(t_param *));
	while (index < pn)
	{
		params[index] = ft_calloc(1, sizeof(t_param));
		params[index]->mutexe = universe->mutexe;
		params[index]->person = universe->humanity[index];
		params[index]->death = universe->death;
		pthread_create(universe->humanity[index].soul, NULL, behaviour,
			params[index]);
		if (index % 2 == 0)
			sleep_ms(index);
		index++;
	}
	return (params);
}
