/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:31:17 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/19 18:03:42 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd("usage: fillit source_file\n", 2);
	else
	{
		ft_putstr(argv[1]);
		// DO PROGRAM
	}
	return (0);
}
