/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:25:45 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/21 11:33:05 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//cree une chaine avec 2 autres chaines concate. 
//penser a la free. 
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_new_str;
	char	*new_str;

	size_new_str = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2) + 1;
	new_str = malloc(size_new_str);
	if (!new_str)
		return (NULL);
	ft_bzero(new_str, size_new_str);
	ft_strlcat(new_str, s1, size_new_str);
	ft_strlcat(new_str, s2, size_new_str);
	return (new_str);
}
