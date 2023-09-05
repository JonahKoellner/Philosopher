/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:41:50 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/05 09:04:50 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	*create_forks(int number)
{
	pthread_mutex_t	*forks;

	forks = ft_calloc(number, sizeof(pthread_mutex_t));
	return (forks);
}

int	clean_mess(int index, t_universe *universe)
{
	int	it;

	it = 0;
	while (it < index)
	{
		free(universe->humanity[it].soul);
		it++;
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

int	create_people(int pn, t_universe *ret_uni)
{
	int	index;

	ret_uni->humanity[0].soul = ft_calloc(1, sizeof(pthread_t));
	if (ret_uni->humanity[0].soul == NULL)
		clean_mess(1, ret_uni);
	ret_uni->humanity[0].forks[0] = pn - 1;
	ret_uni->humanity[0].forks[1] = 0;
	pthread_mutex_init(&ret_uni->mutexe.forks[0], NULL);
	index = 1;
	while (index < pn)
	{
		pthread_mutex_init(&ret_uni->mutexe.forks[index], NULL);
		ret_uni->humanity[index].soul = ft_calloc(1, sizeof(pthread_t));
		if (ret_uni->humanity[index].soul == NULL)
			return (clean_mess(index, ret_uni), 1);
		ret_uni->humanity[index].forks[0] = index - 1;
		ret_uni->humanity[index].forks[1] = index;
		index++;
	}
	return (0);
}

t_universe	*allocate_universe(int pn)
{
	t_universe	*ret_uni;

	ret_uni = ft_calloc(1, sizeof(t_universe));
	if (ret_uni == NULL)
		return (NULL);
	ret_uni->mutexe.print = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(ret_uni->mutexe.print, NULL);
	ret_uni->mutexe.death = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(ret_uni->mutexe.death, NULL);
	ret_uni->mutexe.var_access = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(ret_uni->mutexe.var_access, NULL);
	ret_uni->death = ft_calloc(1, sizeof(int));
	ret_uni->humanity = ft_calloc(pn, sizeof(t_person));
	ret_uni->mutexe.forks = ft_calloc(pn, sizeof(pthread_mutex_t));
	if (create_people(pn, ret_uni) != 0)
		return (NULL);
	return (ret_uni);
}
