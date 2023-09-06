/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:23:25 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 05:41:49 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_personality{
	int			t_eat;
	int			t_die;
	int			t_sleep;
	int			hunger;
	int			eaten;
	int			last_eaten;
}t_personality;

typedef struct s_person {
	int				nr;
	int				forks[2];
	t_personality	perso;
	pthread_t		*soul;
}t_person;

typedef struct s_mutexe{
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
	pthread_mutex_t	*var_access;
	pthread_mutex_t	*forks;
}t_mutexe;

typedef struct s_universe{
	t_person		*humanity;
	int				*death;
	t_mutexe		mutexe;
	long long int	create_moment;
}t_universe;

typedef struct s_param{
	int				*death;
	t_person		*person;
	t_mutexe		mutexe;
	long long int	create_moment;
}t_param;

int			error_check(int argc, char *argv[]);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
t_universe	*allocate_universe(int pn);
t_param		**big_bang(t_universe *universe, int pn);
long long	get_time_ms(void);
int			sleep_ms(int ms);
void		*behaviour(void *param);
int			print_activity(t_param *resource, int nr, char *activity,
				long long int t);
int			big_rip(t_param **params, t_universe *s_universe, int pn);
int			the_end(t_universe *universe, int pn);
int			access_value(pthread_mutex_t *lock, int *value);
int			sleep_ms_death(int ms, t_param *resource);
int			set_value(pthread_mutex_t *lock, int *value, int to_set);
int			access_value(pthread_mutex_t *lock, int *value);

#endif
