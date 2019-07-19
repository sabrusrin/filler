/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/07/20 01:36:07 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include "../libft/get_next_line.h"
#include <fcntl.h>

void	save_data(char **save, int *x, int flag)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		tmp = line;
		if (line[0] != ' ')
		{
			ft_memmove(&(*save[i]), &(line[flag]), *x);
			i += *x + 1;
		}
		line = tmp;
		ft_strdel(&line);
	}
}
/*
void	read_board(t_map *in)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		tmp = line;
		if (line[0] != ' ')
		{
			ft_memmove(&(in->board[i]), &(line[4]), in->size_x)
			i += in->size_x + 1;
		}
		line = tmp;
		ft_strdel(line);
	}
}

void	play_token(t_map *in)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		tmp = line;
		if (line[0] != ' ')
		{
			ft_memmove(&(in->token[i]), &line, in->tx)
			i += in->tx + 1;
		}
		line = tmp;
		ft_strdel(line);
	}

}*/

void	place_token(t_map *in)
{
	int		fd;
	int		y = 8, x = 2;

	fd = open("rdmap", O_WRONLY);
	write(fd, in->board, ft_strlen(in->board));
	write(fd, "\n", 1);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	close(fd);
}

void	dims(char **line, int *x, int *y, int flag)
{
	char	*tmp;
	
	tmp = *line;
	line += flag;
	*y = atoi_move(line);
	*x = atoi_move((++line));
	*line = tmp;
}

void	play(t_map *in)
{
	char	*line;

	while (-1 < (get_next_line(0,  &line)))
	{
		if (ft_strstr(line, "Plateau"))
		{
			dims(&line, &in->x, &in->y, 9);
			in->board = (char*)malloc(in->x * in->y + 1);
			save_data(&(in->board), &(in->x), 4);
		}
		if (ft_strstr(line, "Piece"))
		{
			dims(&line, &in->tx, &in->ty, 6);
			in->token = (char*)malloc(in->tx * in->ty + 1);
			save_data(&(in->token), &(in->tx), 0);
			place_token(in);
		}
		ft_strdel(&line);
	}
	ft_strdel(&(in->board));
	ft_strdel(&(in->token));
}

int		init_player(t_map *in)
{
	char *line;

	get_next_line(0,  &line);
	if (line && (line[10] == '1' || line[10] == '2'))
	{
		if (line[10] == '1')
		{
			in->player[0] = 'O';
			in->player[1] = 'X';
		}
		else
		{
			in->player[0] = 'X';
			in->player[1] = 'O';
		}
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int		main(void)
{
	int		i;
	int 	j;
	char	*line;
	t_map 	in;
	
	if (init_player(&in))
		play(&in);
	else
		return (1);
	return (0);
}
