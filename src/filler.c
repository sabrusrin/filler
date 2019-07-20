/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/07/21 01:45:56 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include "../libft/get_next_line.h"
#include <fcntl.h>

void	save_data(char **save, int x, int flag, int fd)
{
	char	*line;
	char	*tmp;
	int		i;
	int		j;
	static 	int f = 0;
	i = 0;
	j = (flag == 0) ? x : x + 1;
	ft_putstr_fd("X\n", fd);
	while (j--)
	{
		get_next_line(0, &line);
		tmp = line;
		if (line[0] != ' ' || flag == 0)
		{
			ft_memmove(&((*save)[i]), &(line[flag]), x);
			i += x;
		}
		ft_putchar_fd('<', fd);
		ft_putstr_fd(line, fd);
		ft_putnbr_fd(flag, fd);
		ft_putchar_fd('>', fd);
		ft_putchar_fd('\n', fd);

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
	ft_putchar_fd('&', fd);
	write(fd, in->board, in->x * in->y);
	ft_putchar_fd('&', fd);
	write(fd, "\n", 1);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	close(fd);
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
		write(in->fd, "H\n", 2);
			if (!(in->board = (char*)malloc(in->x * in->y + 1)))
				exit (1);
		ft_putstr_fd(line, in->fd);
		ft_putchar_fd('\n', in->fd);

			save_data(&(in->board), (in->y), 4, in->fd);
		}
		if (ft_strstr(line, "Piece"))
		{
		write(in->fd, "4\n", 2);
			dims(&line, &in->tx, &in->ty, 6, in);
			if (!(in->token = (char*)malloc(in->tx * in->ty + 1)))
				exit (1);
			save_data(&(in->token), in->ty, 0, in->fd);
			place_token(in);
		}
		if (in->token)
			ft_strdel(&(in->token));
		if (line)
			ft_strdel(&line);
	}
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


