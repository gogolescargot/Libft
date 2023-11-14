/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:37:14 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/10 14:54:30 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_checkoverflow(long n)
{
	if (n > LONG_MAX / 10)
		return (-1);
	else 
		return (n *= 10);
}

int	ft_atoi(const char *nptr)
{
	long	i;
	long	m;
	long	r;

	i = 0;
	m = 1;
	r = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
	{
		m *= -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		r += nptr[i] - 48;
		if (nptr[i + 1] >= 48 && nptr[i + 1] <= 57)
		{
			if (ft_checkoverflow(r) == -1)
				return (-1);
			r = ft_checkoverflow(r);
		}
		i++;
	}
	return (r * m);
}

int	main (int argc, char **argv)
{
	printf("%d\n%d", ft_atoi(argv[1]), atoi(argv[1]));
}