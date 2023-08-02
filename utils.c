/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:39:51 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/02 10:08:58 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	white_spaces(char c)
{
	return (c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	ret_val;
	int	prefix;
	int	counter;

	counter = 0;
	prefix = 1;
	ret_val = 0;
	while (white_spaces(str[counter]))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			prefix *= -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		ret_val *= 10;
		ret_val += str[counter] - '0';
		counter++;
	}
	return (prefix * ret_val);
}

void	ft_bzero(void *s, size_t n)
{
	int		counter;
	char	*void_cast;

	void_cast = s;
	counter = 0;
	while (counter < (int)n)
	{
		void_cast[counter] = 0;
		counter++;
	}
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_mem;

	if (count != 0)
	{
		if (!count || (count * size) / count != size)
			return (NULL);
	}
	ret_mem = (void *)malloc(count * size);
	if (ret_mem == NULL)
		return (NULL);

	ft_bzero(ret_mem, count * size);
	return (ret_mem);
}
