/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:25:45 by tdeliot           #+#    #+#             */
/*   Updated: 2024/11/21 12:34:59 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//count the number of word 
static int	count_chunk(char const *s, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		if (*s != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		s++;
	}
	return (count);
}

static const char	*begin_word(char const *s, char c)
{
	while (*s && *s == c)
	{
		s++;
	}
	return (s);
}

static int	ft_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	strs_copy(const char *s, char c, int nbr_word, char **new)
{
	int			i;
	char const	*ptr;

	ptr = s;
	i = 0;
	while (i < nbr_word)
	{
		ptr = begin_word(ptr, c);
		new[i] = malloc(ft_len(ptr, c) + 1);
		if (!new[i])
		{
			while (--i >= 0)
			{
				free(new[i]);
			}
			free(new);
			return (-1);
		}
		ft_strlcpy(new[i], ptr, (ft_len(ptr, c) + 1));
		ptr += ft_len(ptr, c);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		nbr_word;

	if (!s)
		return (NULL);
	nbr_word = count_chunk(s, c);
	if (nbr_word == 0)
	{
		new = malloc((1) * sizeof(char *));
		if (!new)
			return (NULL);
		new[0] = NULL;
		return (new);
	}
	new = malloc((nbr_word + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	new[nbr_word] = NULL;
	if (strs_copy(s, c, nbr_word, new) == (-1))
		return (NULL);
	return (new);
}
