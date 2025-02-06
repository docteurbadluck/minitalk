/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:25:45 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/18 17:48:25 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_str(char const *set, char const c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char const	*ft_find_start(char const *s1, char const *set)
{
	while (*s1 && ft_in_str(set, *s1))
	{
		s1++;
	}
	return (s1);
}

static char const	*ft_find_end(char const *s1, char const *set)
{
	const char	*ptr_end;

	ptr_end = s1;
	while (*ptr_end)
	{
		ptr_end++;
	}
	ptr_end--;
	while (ptr_end >= s1 && ft_in_str(set, *ptr_end))
	{
		ptr_end--;
	}
	return (ptr_end);
}

//take away the set char at the begining and at the end
char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*ptr_start;
	char const	*ptr_end;
	char		*new;
	int			len;

	if (!s1 || !set)
		return (NULL);
	ptr_start = ft_find_start(s1, set);
	ptr_end = ft_find_end(s1, set);
	if (*ptr_start == '\0' || ptr_start > ptr_end)
	{
		new = malloc(1);
		if (new)
			new[0] = '\0';
		return (new);
	}
	len = ptr_end - ptr_start + 1;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, ptr_start, (size_t)(len + 1));
	return (new);
}
