/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:36:43 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/05 15:04:29 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_number(char *string)
{
	int	index;

	index = 0;
	if (string[index] == '-' || string[index] == '+')
		index++;
	while (string[index] != 0x00)
	{
		if (!(string[index] >= 48 && string[index] <= 57))
			return (0);
		index++;
	}
	return (1);
}

int	error_check(int argc, char *argv[])
{
	if (argc < 5)
		return (printf("%s nr_philo die eat sleep [hunger]\n", argv[0]), 1);
	if (!is_number(argv[1]) || !is_number(argv[2]) || !is_number(argv[3])
		|| !is_number(argv[4]))
		return (printf("%s nr_philo die eat sleep [hunger]\n", argv[0]), 1);
	if (argc == 6)
	{
		if (!is_number(argv[5]))
			return (printf("%s nr_philo t_die t_eat t_sleep [times_to_eat]\n",
					argv[0]), 1);
		if (ft_atoi(argv[5]) < 0)
			return (printf("%s nr_philo die eat sleep [hunger]\n", argv[0]), 1);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (printf("%s nr_philo t_die t_eat t_sleep [times_to_eat]\n",
				argv[0]), -1);
	if (ft_atoi(argv[1]) == 1)
	{
		printf("%d\t 1 has taken a fork\n", 0);
		sleep_ms(ft_atoi(argv[2]));
		printf("%d\t 1 died\n", ft_atoi(argv[2]));
		return (1);
	}
	return (0);
}
