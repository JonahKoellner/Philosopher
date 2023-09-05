/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:39:35 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/05 08:43:50 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	access_value(pthread_mutex_t *lock, int *value)
{
	int	ret;

	ret = 0;
	if (!pthread_mutex_lock(lock))
	{
		ret = *value;
		pthread_mutex_unlock(lock);
	}
	return (ret);
}

int	set_value(pthread_mutex_t *lock, int *value, int to_set)
{
	if (!pthread_mutex_lock(lock))
	{
		*value = to_set;
		pthread_mutex_unlock(lock);
	}
	return (0);
}

int	get_forks(t_param *p, int left, int right)
{
	if (!pthread_mutex_lock(&p->mutexe.forks[left]))
	{
		print_activity(p, p->person.nr, "has taken a fork", get_time_ms());
		if (pthread_mutex_lock(&p->mutexe.forks[right]))
			return (1);
		print_activity(p, p->person.nr, "has taken a fork", get_time_ms());
		if (get_time_ms() - p->person.perso.last_eaten
			> access_value(p->mutexe.var_access, &p->person.perso.t_die))
		{
			pthread_mutex_unlock(&p->mutexe.forks[right]);
			pthread_mutex_unlock(&p->mutexe.forks[left]);
			print_activity(p, p->person.nr, "died", get_time_ms());
			set_value(p->mutexe.death, p->death, 1);
			return (1);
		}
		print_activity(p, p->person.nr, "is eating", get_time_ms());
		sleep_ms(p->person.perso.t_eat);
		set_value(p->mutexe.var_access, &p->person.perso.eaten,
			(p->person.perso.eaten) + 1);
		p->person.perso.last_eaten = get_time_ms();
		pthread_mutex_unlock(&p->mutexe.forks[right]);
		pthread_mutex_unlock(&p->mutexe.forks[left]);
		return (0);
	}
	return (1);
}

void	*behaviour(void *param)
{
	t_param	*p;
	int		h;

	p = (t_param *)param;
	p->person.perso.last_eaten = get_time_ms();
	h = access_value(p->mutexe.var_access, &p->person.perso.hunger);
	while ((h == -1
			|| access_value(p->mutexe.var_access, &p->person.perso.eaten) < h)
		&& !access_value(p->mutexe.death, p->death))
	{
		print_activity(p, p->person.nr, "is thinking", get_time_ms());
		if (get_forks(p, p->person.forks[0], p->person.forks[1]))
			break ;
		if (p->person.perso.t_die < p->person.perso.t_sleep)
		{
			sleep_ms(p->person.perso.t_die);
			print_activity(p, p->person.nr, "died", get_time_ms());
			set_value(p->mutexe.death, p->death, 1);
			break ;
		}
		sleep_ms(p->person.perso.t_sleep);
	}
	return (NULL);
}
