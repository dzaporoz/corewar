/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:33:01 by dzaporoz          #+#    #+#             */
/*   Updated: 2018/10/24 17:38:56 by dzaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char*)b;
	while (len-- > 0)
	{
		*p = (unsigned char)c;
		p++;
	}
	return (b);
}
