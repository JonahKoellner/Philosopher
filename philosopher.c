/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:29:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/18 10:28:20 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_person	*create_people(int number, t_personality perso)
{
	t_person	*ret_people;
	int			index;

	ret_people = ft_calloc((number + 1), sizeof(t_person));
	if (ret_people == NULL)
		return (NULL);
	index = -1;
	while (++index < number - 1)
		ret_people[index] = (t_person){.nr = index + 1,
			.active = THINK, .perso = perso,
			.fork1 = index, .fork2 = index + 1,
			.stomach = (t_stomach){.times_eaten = 0, .last_eaten_ms = -1}};
	ret_people[index] = (t_person){.nr = index + 1,
		.active = THINK, .perso = perso, .fork1 = index, .fork2 = 0,
		.stomach = (t_stomach){.times_eaten = 0, .last_eaten_ms = -1}};
	return (ret_people);
}

t_universe	*alloc_universe(int pn, t_person *people)
{
	t_universe	*universe;
	int			index;

	universe = ft_calloc(1, sizeof(t_universe));
	if (universe == NULL)
		return (free(people), ft_error(), NULL);
	universe->humans = people;
	universe->souls = ft_calloc(pn + 1, sizeof(pthread_t));
	universe->print_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (universe->souls == NULL || universe->print_mutex == NULL)
		return (clean_up(universe), ft_error(), NULL);
	universe->mutexes = ft_calloc(pn, sizeof(pthread_mutex_t *));
	if (universe->mutexes == NULL)
		return (clean_up(universe), ft_error(), NULL);
	index = 0;
	while (index < pn)
	{
		universe->mutexes[index++] = ft_calloc(1, sizeof(pthread_mutex_t));
		if (universe->mutexes[index - 1] == NULL)
			return (clean_up(universe), ft_error(), NULL);
		pthread_mutex_init(universe->mutexes[index - 1], NULL);
	}
	pthread_mutex_init(universe->print_mutex, NULL);
	return (universe);
}

int	create_universe(int pn, t_person *people)
{
	int				index;
	t_universe		*universe;
	t_param			*param;
	int				*death_flag;

	universe = alloc_universe(pn, people);
	if (universe == NULL)
		return (1);
	index = 0;
	death_flag = ft_calloc(1, sizeof(int));
	if (death_flag == NULL)
		return (clean_up(universe), ft_error(), 1);
	while (index < pn)
	{
		param = ft_calloc(1, sizeof(t_param));
		*param = (t_param){.death_flag = death_flag, .forks = universe->mutexes,
			.person = &universe->humans[index],
			.print_mutex = universe->print_mutex};
		pthread_create(&universe->souls[index], NULL, philosopher_mind, param);
		if (index % 2 == 0)
			sleep_ms(index);
		index++;
	}
	death(death_flag, universe->humans, universe->souls, index);
	// index = 0;
	// while (index < pn)
	// 	pthread_join(universe->souls[index], NULL);
	return (clean_up(universe), free(death_flag), 0);
}

int	main(int argc, char *argv[])
{
	t_personality	personality;
	int				pn;
	t_person		*people;

	if (check_for_error(argc, argv))
		return (1);
	pn = ft_atoi(argv[1]);
	personality.t_die = ft_atoi(argv[2]);
	personality.t_eat = ft_atoi(argv[3]);
	personality.t_sleep = ft_atoi(argv[4]);
	personality.hunger = -1;
	if (argc == 6)
		personality.hunger = ft_atoi(argv[5]);
	people = create_people(pn, personality);
	if (people == NULL)
		return (printf("It seems like I'm not god\n"), 1);
	srand(time(NULL));
	create_universe(pn, people);
	return (0);
}
