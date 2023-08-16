/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:29:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/16 09:14:35 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_person	*create_universe(int number, t_personality perso)
{
	t_person	*ret_universe;
	int			index;

	ret_universe = ft_calloc((number + 1), sizeof(t_person));
	if (ret_universe == NULL)
		return (NULL);
	index = -1;
	while (++index < number - 1)
		ret_universe[index] = (t_person){.nr = index + 1,
			.active = THINK, .perso = perso,
			.fork1 = index, .fork2 = index + 1,
			.stomach = (t_stomach){.times_eaten = 0, .last_eaten_ms = -1}};
	ret_universe[index] = (t_person){.nr = index + 1,
		.active = THINK, .perso = perso, .fork1 = index, .fork2 = 0,
		.stomach = (t_stomach){.times_eaten = 0, .last_eaten_ms = -1}};
	return (ret_universe);
}

int	create_mankind(int pn, t_person *universe)
{
	int				index;
	pthread_t		*souls;
	pthread_mutex_t	**mutex;
	pthread_mutex_t	*print_mutex;
	t_param			*param;
	int				*death_flag;

	souls = ft_calloc(pn, sizeof(pthread_t));
	mutex = ft_calloc(pn, sizeof(pthread_mutex_t *));
	index = 0;
	while (index < pn)
		mutex[index++] = ft_calloc(1, sizeof(pthread_mutex_t));
	print_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (souls == NULL || mutex == NULL || print_mutex == NULL)
		ft_error(souls, mutex, print_mutex, NULL);
	index = -1;
	while (++index < pn)
		pthread_mutex_init(mutex[index], NULL);
	pthread_mutex_init(print_mutex, NULL);
	index = 0;
	death_flag = ft_calloc(1, sizeof(int));
	if (death_flag == NULL)
		ft_error(souls, mutex, print_mutex, NULL);
	while (index < pn)
	{
		param = malloc(sizeof(t_param));
		*param = (t_param){.death_flag = death_flag, .forks = mutex,
			.person = &universe[index], .print_mutex = print_mutex};
		pthread_create(&souls[index], NULL, philosopher_mind, param);
		if (index % 2 == 0)
			sleep_ms(index);
		index++;
	}
	death(death_flag, universe, souls, index);
	return (0);
}

int	check_for_error(int argc, char *argv[])
{
	if (argc < 5)
		return (ft_error(NULL, NULL, NULL, NULL), 1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (printf("%s nr_philo t_die t_eat t_sleep [times_to_eat]\n",
				argv[0]), -1);
	if (ft_atoi(argv[1]) == 1)
	{
		sleep_ms(ft_atoi(argv[2]));
		printf("%lld 1 died\n", get_time_ms());
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_personality	personality;
	int				pn;
	t_person		*universe;

	if (check_for_error(argc, argv))
		return (1);
	pn = ft_atoi(argv[1]);
	personality.t_die = ft_atoi(argv[2]);
	personality.t_eat = ft_atoi(argv[3]);
	personality.t_sleep = ft_atoi(argv[4]);
	personality.hunger = -1;
	if (argc == 6)
		personality.hunger = ft_atoi(argv[5]);
	universe = create_universe(pn, personality);
	if (universe == NULL)
		return (printf("It seems like I'm not god\n"), -1);
	srand(time(NULL));
	create_mankind(pn, universe);
	return (0);
}
