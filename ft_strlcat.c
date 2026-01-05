/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabhi <irabhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:53:32 by irabhi            #+#    #+#             */
/*   Updated: 2024/10/21 22:34:49 by irabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_ind;
	size_t	d_ind;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	d_ind = d_len;
	if (dstsize <= d_len)
		return (dstsize + s_len);
	s_ind = 0;
	while (src[s_ind] && (d_len + s_ind) + 1 < dstsize)
	{
		dst[d_ind + s_ind] = src[s_ind];
		s_ind++;
	}
	dst[d_ind + s_ind] = 0;
	return (d_len + s_len);
}
