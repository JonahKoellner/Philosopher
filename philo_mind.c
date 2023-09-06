/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:39:35 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 06:11:13 by jonahkollne      ###   ########.fr       */
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
	//int	tepm;

	//if (p->person->nr % 2 == 0)
	//{
	//	tepm = left;
	//	left = right;
	//	right = tepm;
	//}
	if (!pthread_mutex_lock(&p->mutexe.forks[left]))
	{
		print_activity(p, p->person->nr, "has taken a fork", get_time_ms());
		if (pthread_mutex_lock(&p->mutexe.forks[right]))
			return (pthread_mutex_unlock(&p->mutexe.forks[left]), 1);
		print_activity(p, p->person->nr, "has taken a fork", get_time_ms());
		print_activity(p, p->person->nr, "is eating", get_time_ms());
		sleep_ms_death(p->person->perso.t_eat, p);
		set_value(p->mutexe.var_access, &p->person->perso.last_eaten,
			get_time_ms() - p->create_moment);
		set_value(p->mutexe.var_access, &p->person->perso.eaten,
			(p->person->perso.eaten) + 1);
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
	h = access_value(p->mutexe.var_access, &p->person->perso.hunger);
	while ((h == -1
			|| access_value(p->mutexe.var_access, &p->person->perso.eaten) < h)
		&& !access_value(p->mutexe.death, p->death))
	{
		//printf("in mind %d %d\n", p->person->forks[0], p->person->forks[1]);
		print_activity(p, p->person->nr, "is thinking", get_time_ms());
		if (get_forks(p, p->person->forks[0], p->person->forks[1]))
		{
			print_activity(p, p->person->nr, "died(err)", get_time_ms());
			set_value(p->mutexe.death, p->death, 1);
			break ;
		}
		print_activity(p, p->person->nr, "is sleeping", get_time_ms());
		sleep_ms_death(p->person->perso.t_sleep, p);
	}
	return (NULL);
}
