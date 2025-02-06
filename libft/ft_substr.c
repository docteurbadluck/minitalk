/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:48:20 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/21 11:32:50 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//dupplicate the len of the string in another one from start. 
char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*sub;

	if (!src)
		return (NULL);
	if (start > (unsigned int)ft_strlen(src))
		return (ft_strdup(""));
	if (len > (unsigned int)ft_strlen(src + start))
		len = ft_strlen(src + start);
	sub = malloc(len + 1);
	if (!sub)
	{
		return (NULL);
	}
	ft_bzero(sub, len + 1);
	ft_strlcpy(sub, src + start, len + 1);
	return (sub);
}
