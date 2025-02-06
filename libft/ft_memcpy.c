/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:48:20 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/26 18:39:58 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copy n bytes from src to dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*value;
	size_t				i;

	if (dest == (void *) 0 && src == (void *) 0)
		return (dest);
	ptr = (unsigned char *) dest;
	value = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		ptr[i] = value[i];
		i++;
	}
	return (dest);
}
