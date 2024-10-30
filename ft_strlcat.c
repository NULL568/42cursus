/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaubry <tiaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:38 by tiaubry           #+#    #+#             */
/*   Updated: 2024/10/16 13:54:00 by tiaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	max_copy;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	max_copy = size - dest_len - 1;
	i = 0;
	if (dest_len >= size)
		return (size + src_len);
	while (src[i] && i < max_copy)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
