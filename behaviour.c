/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:54:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/05/31 13:36:53 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_mind(void	*args)
{
	t_param	*param;
	int		alive;

	alive = 1;
	param = (t_param *)args;
	while (alive)
	{
		pthread_mutex_lock(param->mutex);
		printf("%d\t", param->person.nr);
		alive = rand() % 10;
		if (!alive)
			printf("\n\n%d died\n\n", param->person.nr);
		pthread_mutex_unlock(param->mutex);
	}
	return (args);
}
