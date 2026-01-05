/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabhi <irabhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:14:07 by irabhi            #+#    #+#             */
/*   Updated: 2024/10/21 22:31:05 by irabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	temp;

	i = 0;
	sign = 1;
	temp = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (temp > (LLONG_MAX - (str[i] - '0')) / 10)
			return (check(sign));
		temp = (temp * 10) + (str[i] - '0');
		i++;
	}
	return (temp * sign);
}
