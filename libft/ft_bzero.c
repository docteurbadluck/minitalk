/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:25:45 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/18 11:43:01 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//erases the data in the n bytes of the memory
void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;

	ptr = s;
	while (len--)
	{
		*ptr++ = '\0';
	}
}
