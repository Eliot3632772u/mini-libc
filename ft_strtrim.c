/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabhi <irabhi@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 12:01:06 by irabhi            #+#    #+#             */
/*   Updated: 2024-10-22 12:01:06 by irabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (check(*s1, set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (check(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	new = (char *)malloc(size * sizeof(char) + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, (char *)s1, size + 1);
	return (new);
}
