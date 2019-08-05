/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:26:32 by chermist          #+#    #+#             */
/*   Updated: 2019/08/06 00:39:17 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*join_n_free(char *s1, char const *s2, int cen, int nb)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	if (cen > 0)
	{
		if (!(s1 = ft_realloc(s1, cen, cen + nb)))
			return (NULL);
	}
	else
	{
		free(s1);
		if (!(s1 = malloc(nb)))
			return (NULL);
	}
	tmp = s1;
	s1 += cen;
	while (nb--)
		*s1++ = *s2++;
	return (tmp);
}

int		read_line(const int fd, char **line)
{
	char			buffer;
	static t_line	*curr_l = NULL;
	size_t			rb;

	if ((!line || fd < 0 || read(fd, 0, 0) < 0))
		return (-1);
	while ((rb = read(fd, buffer, 1)))
	{
		if (!(curr_l->con = join_n_free(curr_l->con, buffer, curr_l->c_sz, rb)))
			return (-1);
		if ((curr_l->c_sz += rb) && (ft_strchr(buffer, '\n')))
			break ;
	}
	if (!rb && !curr_l->c_sz)
		return (0);
	if (copy_del(&curr_l, line))
		return (-1);
	return (1);
}
