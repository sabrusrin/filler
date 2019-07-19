/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:06:55 by chermist          #+#    #+#             */
/*   Updated: 2019/07/20 01:33:29 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_map
{
	int 		me;
	int			y;
	int			x;
	int			tx;
	int			ty;
	char		player[2];
	char		*board;
	char		*token;
}				t_map;

unsigned long	atoi_move_hex(char **str);
int				atoi_move(char **str);
#endif
