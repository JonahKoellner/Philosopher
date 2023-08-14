/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:54:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/14 10:58:57 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	eating(t_param *param)
{
	param->person->active = EAT;
	status_print(param->person, param->print_mutex);
	sleep_ms(param->person->perso.t_eat);
	param->person->stomach.last_eaten_ms = get_time_ms();
	param->person->stomach.times_eaten++;
	pthread_mutex_unlock(param->forks[param->person->fork2]);
	pthread_mutex_unlock(param->forks[param->person->fork1]);
	return (0);
}

void	*philosopher_mind(void	*args)
{
	t_param	*param;

	param = (t_param *)args;
	while ((param->person->perso.hunger < 0
			|| param->person->perso.hunger > param->person->stomach.times_eaten)
		&& *param->death_flag == 0)
	{
		if (param->person->stomach.last_eaten_ms == -1)
			param->person->stomach.last_eaten_ms = get_time_ms();
		if (get_time_ms() - param->person->stomach.last_eaten_ms
			> param->person->perso.t_die)
		{
			pthread_mutex_lock(param->print_mutex);
			printf("%lld %d died\n", get_time_ms(), param->person->nr);
			*param->death_flag = 1;
			break ;
		}
		if (!pthread_mutex_lock(param->forks[param->person->fork1])
			&& (!pthread_mutex_lock(param->forks[param->person->fork2])))
		{
			printf("%lld %d has taken a fork\n", get_time_ms(),
				param->person->nr);
			eating(param);
			param->person->active = SLEEP;
			sleep_ms(param->person->perso.t_sleep);
			status_print(param->person, param->print_mutex);
		}
		param->person->active = THINK;
		status_print(param->person, param->print_mutex);
	}
	// printf("philosopher %d out (eaten: %d)\n", param->person->nr,
	// 	param->person->stomach.times_eaten);
	pthread_exit(NULL);
	return (args);
}
