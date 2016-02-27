/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:50:36 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/27 16:43:44 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/p4.h"

void	init_tab(t_board *board)
{
	int 	tmp;
	int 	y;

	y = board->row + 1;
	if (board->row && board->colum)
	{
		board->tab = (char **)ft_memalloc(sizeof(char *) * (board->row));
		if (board->tab)
		{
			while (--y)
			{
				tmp = board->colum + 1;
				board->tab[y] = (char *)ft_memalloc(sizeof(char) * (board->colum));
				while (--tmp)
				{

					board->tab[y][tmp] = '.';
				}
				board->tab[y][tmp] = '\0';
			}
		}
	}
}



static void		put_tab(t_board *board)
{
	int 	x;
	int 	y;

	y = -1;
	while (++y)
	{
		x = -1;
		while (++x)
		{
			ft_printf(" | %d", board->tab[y][x]);
		}
		ft_printf("|");
		ft_printf("\n");
	}
}

int				main(int argc, char **argv)
{
	t_all	all;

	if (argc > 2)
	{
		all.board.row = ft_atoi(argv[1]);
		all.board.colum = ft_atoi(argv[2]);
		init_tab(&all.board);
		put_tab(&all.board);
	}
	return (0);
}
