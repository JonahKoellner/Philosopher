/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:34:58 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/29 16:17:57 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>

typedef enum e_Activity{
	EAT,
	SLEEP,
	THINK
}t_activity;

typedef struct s_personality
{
	int	t_eat;
	int	t_sleep;
	int	t_die;
	int	hunger;
}t_personality;

typedef struct s_person
{
	int				nr;
	t_activity		active;
	t_personality	perso;
}t_person;

typedef struct s_param
{
	t_person		person;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*print_mutex;
}t_param;

int		ft_atoi(const char *str);
void	*philosopher_mind(void	*param);
int		status_print(t_person *philosoper, pthread_mutex_t *print_mutex);

#endif
