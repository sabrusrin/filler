/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 02:39:18 by chermist          #+#    #+#             */
/*   Updated: 2019/09/01 02:39:41 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	distance(t_game *in, int x, int y)
{//THIS FRICKING FUNCTION TAKES TOO MUCH TIME
	int	xe;
	int	ye;
	int	hv;
	int	gv;

	hv = 0;
	gv = 0;
	ye = -1;
	while (++ye < in->board.y && (xe = -1))
		while (++xe < in->board.x)
		{
			if (in->heat[ye][xe][0] == 0) // enemy
				hv = (!hv || hv > ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))))
				? ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))) : hv;
			if (in->heat[ye][xe][1] == 0)// multiplied here by 10
				gv = (!gv || gv > ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))))
				? ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))) : gv;
		}
	in->heat[y][x][0] = hv;
	in->heat[y][x][1] = gv;
}

void	fill_cell(t_game *in)
{
	int	x;
	int	y;
	int	*fcost;

	y = -1;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
		{
			fcost = in->heat[y][x];
			if (in->heat[y][x][0] == 1000)
			{
				distance(in, x, y);
				fcost[2] = fcost[0] + fcost[1];
			}
			else
				fcost[2] = 0;
		}
}
