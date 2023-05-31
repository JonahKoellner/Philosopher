/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/05/31 11:09:22 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	print_activity(t_activity activity)
{
	if (activity == EAT)
		printf("Eating\n");
	else if (activity == SLEEP)
		printf("Sleeping\n");
	else if (activity == THINK)
		printf("THONK\n");
	else
		return (0);
	return (1);
}
