/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:52:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/13 11:38:10 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_createstr(const char *s, int start_location, char c);
static int		ft_countwords(const char *s, char c);

char			**ft_strsplit(const char *s, char c)
{
	char	**str_array;
	char	**head;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	str_array = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!str_array)
		return (NULL);
	head = str_array;
	while (s[i] && s[i] == c)
		i = ++j;
	while (s[i])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
			*str_array++ = ft_createstr(s, j, c);
		while (s[j] && s[j] != c)
			j++;
		i = j;
	}
	*str_array = (NULL);
	return (head);
}

static char		*ft_createstr(const char *s, int start_location, char c)
{
	char	*ptr;
	char	*head;
	int		length;
	int		i;

	length = 0;
	i = start_location;
	while (s[start_location] && s[start_location] != c)
	{
		++length;
		++start_location;
	}
	head = (char *)malloc((length + 1) * sizeof(char));
	if (head)
	{
		ptr = head;
		while (s[i] && s[i] != c)
			*ptr++ = s[i++];
		*ptr = '\0';
	}
	return (head);
}

static int		ft_countwords(const char *s, char c)
{
	int		words;

	while (*s && *s == c)
		s++;
	words = 0;
	while (*s)
	{
		++words;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (words);
}
