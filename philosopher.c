/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:29:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/05/31 13:35:51 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_error(void)
{
	printf("Error accured\n");
}

t_person	*create_universe(int number)
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
		index++;
	}
	return (ret_universe);
}

int	create_mankind(int pn, t_person *universe)
{
	int				index;
	pthread_t		*souls;
	pthread_mutex_t	*mutex;
	t_param			*param;

	souls = malloc(pn * sizeof(pthread_t));
	index = 0;
	mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	while (index < pn)
	{
		param = malloc(sizeof(t_param));
		param->mutex = mutex;
		param->person = universe[index];
		pthread_create(&souls[index], NULL, philosopher_mind, param);
		index++;
	}
	while (index)
		pthread_join(souls[index--], NULL);
	return (0);
}

int	main(int argc, char *argv[])
{
	int			pn;
	t_person	*universe;

	if (!(argc > 1 && argc < 6))
		return (ft_error(), -1);
	pn = ft_atoi(argv[1]);
	printf("Amount of philosophers: %d\n", pn);
	if (pn <= 0)
		return (printf("Negative / Non existence would be wild.\n"), -1);
	universe = create_universe(pn);
	if (universe == NULL)
		return (printf("It seems like I'm not god\n"), -1);
	srand(time(NULL));
	create_mankind(pn, universe);
	return (0);
}
