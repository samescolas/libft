/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:19:38 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/13 11:29:37 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*bkwds_num;
	char	*head;
	int		sign;

	bkwds_num = ft_strnew(ft_numlen(n));
	if (!bkwds_num)
		return (NULL);
	head = bkwds_num;
	if (n < 0)
	{
		sign = -1;
		if (n == -2147483648)
		{
			*bkwds_num++ = '8';
			n /= 10;
		}
		n *= sign;
	}
	else
		sign = 1;
	while (n > 9)
	{
		*bkwds_num++ = (n % 10) + '0';
		n /= 10;
	}
	*bkwds_num++ = n + '0';
	if (sign == -1)
		*bkwds_num++ = '-';
	return (ft_strrev(head));
}
