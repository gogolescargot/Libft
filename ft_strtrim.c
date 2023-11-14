/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:23:10 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/10 23:02:32 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstart(const char *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s1[i]) && i < ft_strlen(s1))
		i++;
	if (i == ft_strlen(s1))
		return (0);
	return (i);
}

int	ft_strend(const char *s1, char const *set)
{
	size_t	i;

	if (!s1[0])
		return (-1);
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i > 0)
		i--;
	if (i == 0)
		return (-1);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		i;

	strtrim = malloc(ft_strend(s1, set) - ft_strstart(s1, set) + 2);
	if (!strtrim)
		return (NULL);
	i = 0;
	while (i + ft_strstart(s1, set) <= ft_strend(s1, set))
	{
		strtrim[i] = s1[i + ft_strstart(s1, set)];
		i++;
	}
	strtrim[i] = 0;
	return (strtrim);
}
