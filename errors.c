/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:14:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/16 09:14:28 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_error(pthread_t *s, pthread_mutex_t **m, pthread_mutex_t *p, int *d)
{
	int	index;

	index = 0;
	if (s != NULL)
		free(s);
	if (m != NULL)
	{
		while (m[index] != NULL)
			free(m[index]);
		free(m);
	}
	if (p != NULL)
		free(p);
	if (d != NULL)
		free(d);
	printf("Error occured\n");
}
