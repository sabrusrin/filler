/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:06:55 by chermist          #+#    #+#             */
/*   Updated: 2019/05/28 23:24:24 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_map
{
	int			n;
	int			x;
	char		*player[2];
	char		*board;
}				t_map;

#endif
