/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabhi <irabhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:09:51 by irabhi            #+#    #+#             */
/*   Updated: 2024/10/21 22:34:24 by irabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr1;

	if (n == 0)
		return (0);
	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	while ((*ptr == *ptr1) && n - 1 > 0)
	{
		ptr++;
		ptr1++;
		n--;
	}
	return ((int)(*ptr - *ptr1));
}
