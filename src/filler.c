/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/07/07 23:09:28 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_data(int flag, t_map *in, char *line)
{
	while (line)
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
	while (get_next_line(0,  *line))
	{
		if (ft_strstr(*line, "Plateau"))
		{
			tmp = *line;
			*line += 9;
			y = atoi_move(line);
			x = atoi_move(++(*line));
			*line = tmp;
			board = (char *)malloc(x * y + 1);
			read_board()
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
	if (!line[10] || (line[10] != '1' && line[10] != '2'))
		ft_putendl_fd("error about player position", 2);
	else
	{
		in.player[0] = (line[10] == '1' ? 'O' : 'X');
		in.player[1] = (line[10] == '1' ? 'X' : 'O');
		while (1)
			play(&in, &line);
	}
	
	free(&in);
	return (0);
}
