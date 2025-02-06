/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:48:20 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/21 11:35:19 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copy the src in the dest and avoid overlaping.
// exemple sans traite overlap string ABCD
//cp(str[0], str[1]) on decale de 1 la chaine vers la droite  
//str[1] = str[0] 
//str = AACD
//str[2] = str[1];
//str = AAAD; 
// MISTAKE
// to avoid the mistake memmove copy en partant de la fin.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	size_t				i;
	const unsigned char	*ptr_s;

	ptr_d = (unsigned char *) dest;
	ptr_s = (const unsigned char *) src;
	if (ptr_d == ptr_s)
		return (dest);
	if (ptr_d >= ptr_s && ptr_d < ptr_s + n)
	{
		i = n + 1;
		while (--i > 0)
			ptr_d[i - 1] = ptr_s[i - 1];
	}
	else
	{
		i = -1;
		while (++i < n)
			ptr_d[i] = ptr_s[i];
	}
	return (dest);
}
