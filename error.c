/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:36:43 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/05 08:38:13 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	error_check(int argc, char *argv[])
{
	if (argc < 5)
		return (printf("%s nr_philo t_die t_eat t_sleep [times_to_eat]\n",
				argv[0]), 1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (printf("%s nr_philo t_die t_eat t_sleep [times_to_eat]\n",
				argv[0]), -1);
	if (ft_atoi(argv[1]) == 1)
	{
		printf("%lld 1 has taken a fork\n", get_time_ms());
		sleep_ms(ft_atoi(argv[2]));
		printf("%lld 1 died\n", get_time_ms());
		return (1);
	}
	return (0);
}
