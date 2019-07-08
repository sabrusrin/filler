/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/07/08 23:12:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_data(int flag, t_map *in, char *line)
{
	while (line)
	{
			
	}
		
}

void	read_board(t_map *in)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		
	}
}

void	play_token(t_map *in, char **line)
{

}

void	play(t_map *in, char **line)
{
	char	*tmp;

	ft_strdel(*line);
	while (-1 < (get_next_line(0,  *line)))
	{
		if (ft_strstr(*line, "Plateau"))
		{
			tmp = *line;
			*line += 9;
			in->size_y = atoi_move(line);
			in->size_x = atoi_move(++(*line));
			*line = tmp;
			in->board = (char *)malloc(x * y + 1);
			read_board(in);
		}
		if (ft_strstr(*line, "Piece"))
			play_token(in, line);
		ft_strdel(*line);
	}
}

int main(void)
{
	int		i;
	int 	j;
	char	*line;
	t_map 	in;
	
	get_next_line(0,  &line);
	if (line && (line[10] == '1' || line[10] == '2'))
	{
		if (ft_strstr(*line, "chermist"))
		{
			in.player[0] = 'O';
			in.player[1] = 'X';
		}
		else
		{
			in.player[0] = 'X';
			in.player[1] = 'O';
		}

		play(&in, &line);
	}
	else
		return (1);
	
	free(&in);
	return (0);
}
