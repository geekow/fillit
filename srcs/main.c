/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:31:17 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/21 18:08:41 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	size_t	nb_tetri;

	if (argc != 2)
		ft_putstr_fd("usage: fillit source_file\n", 2);
	else
	{
		nb_tetri = 0;
		if ((list = stock_tetri(argv[1], &nb_tetri)) != NULL)
		{
			fillit(list, nb_tetri);
			return (0);
		}
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}
