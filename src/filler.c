/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/07/21 23:42:38 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include "../libft/get_next_line.h"
#include <fcntl.h>

void	save_data(char **save, int x, int y, int flag)
{
	char	*line;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = (flag == 0) ? y : y + 1;
	line = NULL;
	while (j--)
	{
		get_next_line(0, &line);
		tmp = line;
		if (line[0] != ' ' || flag == 0)
		{
			ft_memmove(&((*save)[i]), &(line[flag]), x);
			i += x;
		}
		line = tmp;
		if (line)
			ft_strdel(&line);
	}
}

void	place_token(t_map *in)
{
	int		fd;
	int		y = 8, x = 2;

	write(in->fd, "Z\n", 2);
	fd = open("rdmap", O_WRONLY);
	ft_putchar_fd('&', in->fd);
	write(in->fd, in->board, in->x * in->y);
	ft_putchar_fd('&', in->fd);
	write(fd, "\n", 1);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	close(fd);
	close(in->fd);
}

void	dims(char **line, int *x, int *y, int flag, t_map *in)
{
	char	*tmp;
	
	tmp = *line;
	*line += flag;
	*y = atoi_move(line);
	*line += 1;
	*x = atoi_move((line));
	*line = tmp;
}

void	play(t_map *in)
{
	char	*line;

	while (-1 < (get_next_line(0,  &line)))
	{
		if (ft_strstr(line, "Plateau"))
		{
		write(in->fd, "3\n", 2);
			dims(&line, &in->x, &in->y, 8, in);
			if (!(in->board = ft_strnew(in->x * in->y)))
				exit (1);
			save_data(&(in->board), in->x, in->y, 4);
		}
		if (ft_strstr(line, "Piece"))
		{
		write(in->fd, "4\n", 2);
			dims(&line, &in->tx, &in->ty, 6, in);
			if (!(in->tile = ft_strnew(in->tx * in->ty)))
				exit (1);
			save_data(&(in->tile), in->tx, in->ty, 0, in->fd);
			place_token(in);
		}
		if (in->token)
			ft_strdel(&(in->tile));
		if (line)
			ft_strdel(&line);
	}
	if (in->board)
		ft_strdel(&(in->board));
}

int		init_player(t_map *in)
{
	char *line;

	get_next_line(0,  &line);
	write(in->fd, "1\n", 2);
	if (line && (line[10] == '1' || line[10] == '2'))
	{
		write(in->fd, "2\n", 2);
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
	
	in.fd = open("trace", O_WRONLY);
	if (init_player(&in))
		play(&in);
	else
		return (1);
	return (0);
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


