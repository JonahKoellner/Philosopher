/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:41:50 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/04 19:34:55 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	*create_forks(int number)
{
	pthread_mutex_t	*forks;

	forks = ft_calloc(number, sizeof(pthread_mutex_t));
	return (forks);
}

int	create_people(int pn, t_universe *ret_uni)
{
	int	index;

	ret_uni->humanity[0].soul = ft_calloc(1, sizeof(pthread_t));
	index = 1;
	ret_uni->humanity[0].forks[0] = pn - 1;
	ret_uni->humanity[0].forks[1] = 0;
	while (index < pn)
	{
		pthread_mutex_init(&ret_uni->mutexe.forks[index], NULL);
		ret_uni->humanity[index].soul = ft_calloc(1, sizeof(pthread_t));
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
	ret_uni->mutexe.print = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(ret_uni->mutexe.print, NULL);
	ret_uni->mutexe.death = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(ret_uni->mutexe.death, NULL);
	ret_uni->mutexe.var_access = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(ret_uni->mutexe.var_access, NULL);
	ret_uni->death = ft_calloc(1, sizeof(int));
	ret_uni->humanity = ft_calloc(pn, sizeof(t_person));
	ret_uni->mutexe.forks = ft_calloc(pn, sizeof(pthread_mutex_t));
	create_people(pn, ret_uni);
	return (ret_uni);
}
