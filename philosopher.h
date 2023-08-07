/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:34:58 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/07 13:03:35 by jkollner         ###   ########.fr       */
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

// typedef struct s_stomach
// {
	// int	last_eaten_ms;
	// int	times_eaten;
// }t_stomach;

typedef struct s_person
{
	int				nr;
	int				eaten;
	// t_stomach		stomach;
	int				fork1;
	int				fork2;
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
void	*ft_calloc(size_t count, size_t size);
void	*philosopher_mind(void	*param);
int		status_print(t_person *philosoper, pthread_mutex_t *print_mutex);

#endif
