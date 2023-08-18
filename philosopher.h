/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:34:58 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/18 08:52:19 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

/**
 * 	EAT,
	SLEEP,
	THINK
*/
typedef enum e_Activity{
	EAT,
	SLEEP,
	THINK,
	TAKEN
}t_activity;

/**
 * 	int	t_eat;
	int	t_sleep;
	int	t_die;
	int	hunger;
*/
typedef struct s_personality
{
	int	t_eat;
	int	t_sleep;
	int	t_die;
	int	hunger;
}t_personality;

/**
 * 	long long	last_eaten_ms;
	int			times_eaten;
*/
typedef struct s_stomach
{
	long long	last_eaten_ms;
	int			times_eaten;
}t_stomach;

/**
 * 	int				nr;
	t_stomach		stomach;
	int				fork1;
	int				fork2;
	t_activity		active;
	t_personality	perso;
*/
typedef struct s_person
{
	int				nr;
	t_stomach		stomach;
	int				fork1;
	int				fork2;
	t_activity		active;
	t_personality	perso;
}t_person;

/**
 * 	t_person		*person;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*print_mutex;
	int				*death_flag;
*/
typedef struct s_param
{
	t_person		*person;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*print_mutex;
	int				*death_flag;
}t_param;

/**
 * 	t_person		*humans;
	pthread_t		*souls;
	pthread_mutex_t	**mutexes;
	pthread_mutex_t	*print_mutex;
*/
typedef struct s_universe
{
	t_person		*humans;
	pthread_t		*souls;
	pthread_mutex_t	**mutexes;
	pthread_mutex_t	*print_mutex;
}t_universe;

int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		*philosopher_mind(void	*param);
int	status_print(t_person *philo, pthread_mutex_t *print_mutex, t_activity new);
long long	get_time_ms(void);
int			sleep_ms(int ms);
int			death(int *death, t_person *universe, pthread_t *souls, int index);
void		ft_error(void);
void		clean_up(t_universe *universe);
int			check_for_error(int argc, char *argv[]);

#endif
