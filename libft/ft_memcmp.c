/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:48:20 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/18 12:11:22 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compare byte by byte for  n raw block 
//usefull for compare things without nullterminating. 
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
		{
			return ((int)(*ptr1 - *ptr2));
		}
		ptr1++;
		ptr2++;
	}
	return (0);
}
