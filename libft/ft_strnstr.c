/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:48:20 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/26 18:55:50 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//search a string in a string. 
//if the searched string needle is '\0' we can find it everywhere
// it return the haystack
//otherwise, it return a ptr on the begining of the string.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
		j = '\0';
	}
	return (0);
}
