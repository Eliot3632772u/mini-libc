/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabhi <irabhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:02:45 by irabhi            #+#    #+#             */
/*   Updated: 2024/10/21 22:31:31 by irabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (((count * size) / count) != size)
		return (0);
	array = (void *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}
