/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:34:58 by jkollner          #+#    #+#             */
/*   Updated: 2023/05/31 13:36:40 by jkollner         ###   ########.fr       */
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

typedef struct s_person
{
	int			nr;
	t_activity	active;
}t_person;

typedef struct s_param
{
	t_person		person;
	pthread_mutex_t	*mutex;
}t_param;

int		ft_atoi(const char *str);
void	*philosopher_mind(void	*param);
int		print_activity(t_activity activity);

#endif
