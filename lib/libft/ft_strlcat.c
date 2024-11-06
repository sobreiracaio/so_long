/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:04:33 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/06 20:44:07 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	sum;

	i = 0;
	sum = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size > dest_len)
		sum = dest_len + src_len;
	else
		return (src_len + size);
	while (src[i] && (dest_len + 1) < size)
		dst[dest_len++] = src[i++];
	dst[dest_len] = '\0';
	return (sum);
}
