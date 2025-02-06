/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:48:20 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/21 11:34:30 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return the last occurance of a char in a string.
char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	char			*ptr;

	ch = (unsigned char)c;
	ptr = 0;
	while (*s)
	{
		if (*s == ch)
		{
			ptr = (char *)s;
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (ptr);
}
