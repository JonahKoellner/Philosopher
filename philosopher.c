/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:29:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/29 16:20:47 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_error(void)
{
	printf("Error accured\n");
}

t_person	*create_universe(int number, t_personality perso)
{
	t_person	*ret_universe;
	int			index;

	ret_universe = malloc(number * sizeof(t_person));
	if (ret_universe == NULL)
		return (NULL);
	index = 0;
	while (index < number)
	{
		ret_universe[index].nr = index + 1;
		ret_universe[index].active = THINK;
		ret_universe[index].perso = perso;
		index++;
	}
	return (ret_universe);
}

int	create_mankind(int pn, t_person *universe)
{
	int				index;
	pthread_t		*souls;
	pthread_mutex_t	**mutex;
	pthread_mutex_t	*print_mutex;
	t_param			*param;

	souls = malloc(pn * sizeof(pthread_t));
	index = -1;
	mutex = malloc(pn * sizeof(pthread_mutex_t *));
	print_mutex = malloc(sizeof(pthread_mutex_t));
	while (++index < pn)
		pthread_mutex_init(mutex[index], NULL);
	index = 0;
	while (index < pn)
	{
		param = malloc(sizeof(t_param));
		param->forks = mutex;
		param->print_mutex = print_mutex;
		param->person = universe[index];
		pthread_create(&souls[index], NULL, philosopher_mind, param);
		index++;
	}
	index -= 1; //thread join error
	while (index)
		pthread_join(souls[index--], NULL);
	return (0);
}

int	check_for_error(int argc, char *argv[])
{
	if (argc < 6)
		return (ft_error(), 1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (printf("Negative time / Non existence would be wild.\n"), -1);
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
	if (argc == 5)
		personality.hunger = ft_atoi(argv[5]);
	universe = create_universe(pn, personality);
	if (universe == NULL)
		return (printf("It seems like I'm not god\n"), -1);
	srand(time(NULL));
	create_mankind(pn, universe);
	return (0);
}
