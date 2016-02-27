/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:51:21 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/27 16:27:19 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P4_H
# define P4_H
# include "../libft/includes/libft.h"

typedef struct	s_board
{
		int		row;
		int		colum;
		char	**tab;
}				t_board;

typedef struct	s_all
{
	struct s_board	board;
}				t_all;

#endif
