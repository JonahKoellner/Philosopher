/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:35:44 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/04 19:42:33 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	fill_personalities(t_person *humanity, char	*argv[], int pn)
{
	int				index;
	t_personality	perso;

	index = 0;
	perso.eaten = 0;
	perso.t_die = ft_atoi(argv[2]);
	perso.t_eat = ft_atoi(argv[3]);
	perso.t_sleep = ft_atoi(argv[4]);
	perso.hunger = -1;
	if (argv[5])
		perso.hunger = ft_atoi(argv[5]);
	while (index < pn)
	{
		humanity[index].perso = perso;
		humanity[index].nr = index + 1;
		index++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_universe	*universe;
	t_param		**clean_params;
	int			pn;

	if (error_check(argc, argv))
		return (1);
	pn = ft_atoi(argv[1]);
	universe = allocate_universe(pn);
	if (universe == NULL)
		return (printf("Allocation Error \n"), 1);
	fill_personalities(universe->humanity, argv, pn);
	clean_params = big_bang(universe, pn);
	the_end(universe, pn);
	big_rip(clean_params, universe, pn);
	return (0);
}
