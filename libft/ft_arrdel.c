/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:56:53 by chermist          #+#    #+#             */
/*   Updated: 2019/08/02 00:36:00 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arrdel(void **res)
{
	void	**tmp;

	tmp = res;
	if (res && *res)
	{
		while (*res)
			ft_memdel(*res++);
		ft_memdel(tmp);
	}
	return (tmp);
}
