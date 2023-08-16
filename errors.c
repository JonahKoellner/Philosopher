/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:14:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/16 10:30:12 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	clean_up(t_universe *universe)
{
	int	index;

	if (universe->humans != NULL)
		free(universe->humans);
	if (universe->souls != NULL)
		free(universe->souls);
	if (universe->print_mutex != NULL)
		free(universe->print_mutex);
	index = 0;
	if (universe->mutexes != NULL)
	{
		while (universe->mutexes[index] != NULL)
			free(universe->mutexes[index++]);
		free(universe->mutexes);
	}
}

int	check_for_error(int argc, char *argv[])
{
	if (argc < 5)
		return (ft_error(), 1);
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

void	ft_error(void)
{
	printf("Error occured\n");
}
