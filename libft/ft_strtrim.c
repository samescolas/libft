/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:38:45 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/13 10:47:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwhitespace(char *s);

char		*ft_strtrim(const char *s)
{
	char	*str;
	char	*head;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s) - ft_countwhitespace((char *)s);
	head = (char *)malloc((len + 1) * sizeof(char));
	if (head)
	{
		str = head;
		while (*s && ft_iswhitespace(*s))
			++s;
		while (len)
		{
			*str++ = *s++;
			--len;
		}
		*str = '\0';
	}
	return (head);
}

static int	ft_countwhitespace(char *s)
{
	int	word;
	int	count;

	word = 0;
	count = 0;
	while (ft_iswhitespace(*s))
	{
		++count;
		++s;
	}
	if (!*s)
		return (count);
	while (*s)
		++s;
	--s;
	while (*s && ft_iswhitespace(*s))
	{
		++count;
		--s;
	}
	return (count);
}
